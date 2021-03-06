/* -*- c++ -*- */
/* 
 * Copyright 2016 Johannes Demel.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include <gfdm/detect_frame_energy_kernel_cl.h>
#include <volk/volk.h>
#include <iostream>

namespace gr {
  namespace gfdm {

    detect_frame_energy_kernel_cl::detect_frame_energy_kernel_cl(float alpha, int average_len)
        : d_alpha(alpha), d_average_len(average_len)
    {
      set_initial_energy_value(47110815.0f);
    }

    detect_frame_energy_kernel_cl::~detect_frame_energy_kernel_cl()
    {
    }

    long
    detect_frame_energy_kernel_cl::detect_frame(const gfdm_complex* p_in, const int ninput_items)
    {
      // things change. Choose an arbitrary initial value on first call!
      const int nblocks = (ninput_items / d_average_len);
      gfdm_complex res = gfdm_complex(0.0, 0.0);
      for(int i = 0; i < nblocks; ++i){
        volk_32fc_x2_conjugate_dot_prod_32fc(&res, p_in, p_in, d_average_len);
        if(d_alpha * d_block_energy < res.real()){
          d_block_energy = res.real();
          return i * d_average_len;
        }
        else{
          d_block_energy = res.real();
        }
        p_in += d_average_len;
      }
      return -1;
    }

  } /* namespace gfdm */
} /* namespace gr */

