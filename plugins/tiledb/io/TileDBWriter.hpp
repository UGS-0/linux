/******************************************************************************
 * Copyright (c) 2019 TileDB, Inc
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following
 * conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of Hobu, Inc. or Flaxen Geo Consulting nor the
 *       names of its contributors may be used to endorse or promote
 *       products derived from this software without specific prior
 *       written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 ****************************************************************************/

#pragma once

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <pdal/Streamable.hpp>
#include <pdal/Writer.hpp>

#include <tiledb/tiledb>

namespace pdal
{

class PDAL_DLL TileDBWriter : public Writer, public Streamable
{
public:
    struct DimBuffer
    {
        std::string m_name;
        Dimension::Id m_id;
        Dimension::Type m_type;
        size_t m_dim_size;
        std::vector<uint8_t> m_buffer;

        DimBuffer(const std::string& name, Dimension::Id id,
                  Dimension::Type type, size_t dimSize)
            : m_name(name), m_id(id), m_type(type), m_dim_size(dimSize)
        {
        }

        inline void resizeBuffer(size_t nelements)
        {
            m_buffer.resize(m_dim_size * nelements);
        }
    };

    TileDBWriter();
    ~TileDBWriter();
    std::string getName() const;

private:
    virtual void addArgs(ProgramArgs& args);
    virtual void initialize();
    virtual void ready(PointTableRef table);
    virtual void write(const PointViewPtr view);
    virtual bool processOne(PointRef& point);
    virtual void done(PointTableRef table);

    bool flushCache(size_t size);

    struct Args;
    std::unique_ptr<TileDBWriter::Args> m_args;

    size_t m_current_idx;

    std::unique_ptr<tiledb::Context> m_ctx;
    std::unique_ptr<tiledb::Array> m_array;
    std::vector<DimBuffer> m_buffers;

    TileDBWriter(const TileDBWriter&) = delete;
    TileDBWriter& operator=(const TileDBWriter&) = delete;
};

} // namespace pdal
