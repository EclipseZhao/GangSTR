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

#include <set>

#include "src/options.h"
#include "src/region_reader.h"
#include "src/locus.h"
#include "src/bam_io.h"
#include "src/ref_genome.h"
#include "gsl/gsl_statistics_int.h"

#ifndef BAM_INFO_H_
#define BAM_INFO_H_

struct SampleProfile {
  std::string rg_sample;
  std::string rg_id;
  double dist_mean;
  double dist_sdev;
  double coverage;
  std::vector<double> gc_coverage;
  std::vector<double> dist_pdf;
  std::vector<double> dist_cdf;
  std::vector<double> dist_integral;
};

class BamInfoExtract{
public:
	BamInfoExtract(const Options* options_,
		       BamCramMultiReader* bamreader_, 
		       RegionReader* region_reader_,
		       const RefGenome* ref_genome_);
	~BamInfoExtract();
	bool GetReadLen(int32_t* read_len);

	bool GetInsertSizeDistribution(std::map<std::string, SampleProfile>* profile,
				       const std::set<std::string> samples,
				       std::map<std::string, std::string> rg_ids_to_sample,
				       bool custom_read_groups);

	bool GetCoverage(std::map<std::string, SampleProfile>* profile,
			 const std::set<std::string> samples,
			 std::map<std::string, std::string> rg_ids_to_sample,
			 bool custom_read_groups);

	bool GetCoverageGC(std::map<std::string, SampleProfile>* profile,
			   const std::set<std::string> samples,
			   std::map<std::string, std::string> rg_ids_to_sample,
			   bool custom_read_groups);
 private:
	const Options* options;
	BamCramMultiReader* bamreader;
	RegionReader* region_reader;
	const RefGenome* ref_genome;
	Locus locus;
};


#endif

