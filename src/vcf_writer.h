/*
Copyright (C) 2017 Melissa Gymrek <mgymrek@ucsd.edu>
and Nima Mousavi (mousavi@ucsd.edu)

This file is part of GangSTR.

GangSTR is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GangSTR is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GangSTR.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SRC_VCF_WRITER_H
#define SRC_VCF_WRITER_H__

#include <iostream>
#include <fstream>

#include "src/locus.h"
#include "src/sample_info.h"
#include "src/ref_genome.h"

using namespace std;

class VCFWriter {
 public:
  VCFWriter(const std::string& _vcffile, const std::string& full_command,
	    const RefGenome& refgenome,
	    SampleInfo& _sample_info, bool _include_ggl);
  void WriteRecord(Locus& locus);
  const std::string GetGGLString(Locus& locus, const std::string& samp);
  virtual ~VCFWriter();
 private:
  ofstream writer_;
  std::vector<std::string> sample_names;
  SampleInfo* sample_info;
  bool include_ggl;
};

#endif  // SRC_VCF_WRITER_H__
