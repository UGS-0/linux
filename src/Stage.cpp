/******************************************************************************
* Copyright (c) 2011, Michael P. Gerlek (mpg@flaxen.com)
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

#include <libpc/Stage.hpp>

namespace libpc
{


Stage::Stage()
    : m_header(NULL)
    , m_currentPointIndex(0)
{
    return;
}


Stage::~Stage()
{
    delete m_header;
    return;
}


void Stage::setCurrentPointIndex(boost::uint64_t currentPointIndex)
{
    m_currentPointIndex = currentPointIndex;
}


boost::uint64_t Stage::getCurrentPointIndex() const
{
    return m_currentPointIndex;
}

void Stage::incrementCurrentPointIndex(boost::uint64_t delta)
{
    m_currentPointIndex += delta;
}


const Header& Stage::getHeader() const
{
    assert(m_header);
    return *m_header;
}


Header& Stage::getHeader()
{
    assert(m_header);
    return *m_header;
}


void Stage::setHeader(Header* header)
{
    delete m_header;
    m_header = header;
}


boost::uint32_t Stage::read(PointData& data, const Bounds<double>& bounds)
{
    const boost::uint32_t numPointsRead = readBuffer(data, bounds);
    return numPointsRead;
}


boost::uint64_t Stage::getNumPoints() const
{
    return getHeader().getNumPoints();
}


bool Stage::atEnd() const
{
    return getCurrentPointIndex() >= getNumPoints();
}


} // namespace libpc
