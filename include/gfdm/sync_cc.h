/* -*- c++ -*- */
/* 
 * Copyright 2016 Andrej Rode.
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


#ifndef INCLUDED_GFDM_SYNC_CC_H
#define INCLUDED_GFDM_SYNC_CC_H

#include <gfdm/api.h>
#include <gnuradio/block.h>
#include <gfdm/preamble_generator.h>

namespace gr {
  namespace gfdm {

    /*!
     * \brief <+description of block+>
     * \ingroup gfdm
     *
     */
    class GFDM_API sync_cc : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<sync_cc> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of gfdm::sync_cc.
       *
       * To avoid accidental use of raw pointers, gfdm::sync_cc's
       * constructor is in a private implementation
       * class. gfdm::sync_cc::make is the public interface for
       * creating new instances.
       */
      static sptr make(int n_subcarriers, int cp_length, int frame_len, std::vector<gr_complex> preamble,
                       const std::string &gfdm_tag_key = "gfdm_block");
    };

  } // namespace gfdm
} // namespace gr

#endif /* INCLUDED_GFDM_SYNC_CC_H */

