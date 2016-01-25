/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "receiver_cc_impl.h"

namespace gr {
  namespace gfdm {

    receiver_cc::sptr
    receiver_cc::make(int nsubcarrier,
                      int ntimeslots,
                      double filter_alpha,
                      int fft_len,
                      const std::string& len_tag_key)
    {
      return gnuradio::get_initial_sptr
        (new receiver_cc_impl(nsubcarrier,
                              ntimeslots,
                              filter_alpha,
                              fft_len,
                              len_tag_key));
    }

    /*
     * The private constructor
     */
    receiver_cc_impl::receiver_cc_impl(int nsubcarrier,
                                        int ntimeslots,
                                        double filter_alpha,
                                        int fft_len,
                                        const std::string& len_tag_key)
      : gr::tagged_stream_block("receiver_cc",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)), len_tag_key),
      d_nsubcarrier(nsubcarrier),
      d_ntimeslots(ntimeslots),
      d_N(ntimeslots*nsubcarrier),
      d_fft_len(fft_len)
    {}

    /*
     * Our virtual destructor.
     */
    receiver_cc_impl::~receiver_cc_impl()
    {
    }

    int
    receiver_cc_impl::calculate_output_stream_length(const gr_vector_int &ninput_items)
    {
      int noutput_items = d_nsubcarrier*d_ntimeslots;
      if (ninput_items[0] < d_fft_len)
      {
        throw std::runtime_error("frame_len must be equal to or greater than fft_len");
      }
      return noutput_items;
    }

    int
    receiver_cc_impl::work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        const gr_complex *in = (const gr_complex *) input_items[0];
        gr_complex *out = (gr_complex *) output_items[0];

        // 1. FFT on input
        // 2. Extract subcarrier
        // 3. Filter and superposition every subcarrier
        // 4. apply ifft on every filtered and superpositioned subcarrier
        // (5.) Provide hooks for advanced IC-Receiver

        return noutput_items;
    }

  } /* namespace gfdm */
} /* namespace gr */

