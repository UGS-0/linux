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

#pragma once

// This file is for all the things that basically everybody has to include.

#include <iostream>

#include <pdal/pdal_export.hpp>
#include <pdal/pdal_types.hpp>

// This is an extraction from the gtest header.  It allows us to make test
// functions friends of classes without including the gtest headers.
#ifndef FRIEND_TEST
#define FRIEND_TEST(test_case_name, test_name)\
friend class test_case_name##_##test_name##_Test
#endif

#ifdef _WIN32
#ifdef _MSC_VER
#define PDAL_MSVC       // Using the MSVC compiler for WIN32.
#define PDAL_WIN32_STL    // When you're using the MSVC compiler, you can use MSVC STL extensions
#else
#ifndef __MINGW32__
#error "WIN32 without MSVC. Expected __MINGW32__ but not found."
#endif
#define PDAL_MINGW      // MinGW runs on WIN32 but isn't MSVC. It uses libc++std.
// MinGW use libstdc++
#endif // _MSC_VER
#endif // _WIN32
