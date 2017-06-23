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

#include "src/tests/ReadClass_test.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(ReadClassTest);

void ReadClassTest::setUp() {
  encl_class_.Reset();
  span_class_.Reset();
  frr_class_.Reset();
}

void ReadClassTest::tearDown() {}

void ReadClassTest::test_AddData() {
  int32_t test_data1 = 10;
  int32_t test_data2 = 20;
  int32_t test_data3 = 30;
  encl_class_.AddData(test_data1);
  encl_class_.AddData(test_data2);
  span_class_.AddData(test_data1);
  span_class_.AddData(test_data2);
  span_class_.AddData(test_data3);
  frr_class_.AddData(test_data1);
  CPPUNIT_ASSERT_EQUAL((int)encl_class_.GetDataSize(), 2);
  CPPUNIT_ASSERT_EQUAL((int)span_class_.GetDataSize(), 3);
  CPPUNIT_ASSERT_EQUAL((int)frr_class_.GetDataSize(), 1);
}

void ReadClassTest::test_Reset() {
  int32_t test_data1 = 10;
  int32_t test_data2 = 20;
  int32_t test_data3 = 30;
  encl_class_.AddData(test_data1);
  encl_class_.AddData(test_data2);
  span_class_.AddData(test_data1);
  span_class_.AddData(test_data2);
  span_class_.AddData(test_data3);
  frr_class_.AddData(test_data1);
  encl_class_.Reset();
  span_class_.Reset();
  frr_class_.Reset();
  CPPUNIT_ASSERT_EQUAL((int)encl_class_.GetDataSize(), 0);
  CPPUNIT_ASSERT_EQUAL((int)span_class_.GetDataSize(), 0);
  CPPUNIT_ASSERT_EQUAL((int)frr_class_.GetDataSize(), 0);
}

void ReadClassTest::test_SpanClassProb() {
  // Example - TODO change
  int32_t allele = 5;
  double log_class_prob = 0.5;
  span_class_.GetLogClassProb(allele, &log_class_prob);
  CPPUNIT_ASSERT_EQUAL(log_class_prob, 0.5);
  CPPUNIT_FAIL("test_SpanClassProb not implemented");
}

void ReadClassTest::test_SpanReadProb() {
  // Example - TODO change
  int32_t allele = 5;
  double log_allele_prob = 0.5;
  int32_t data = 10;
  span_class_.GetLogReadProb(allele, data, &log_allele_prob);
  CPPUNIT_ASSERT_EQUAL(log_allele_prob, 0.5);
  CPPUNIT_FAIL("test_SpanClassProb not implemented");
}

void ReadClassTest::test_FRRClassProb() {
  CPPUNIT_FAIL("test_FRRClassProb not implemented");
}

void ReadClassTest::test_FRRReadProb() {
  CPPUNIT_FAIL("test_FRRClassProb not implemented");
}

void ReadClassTest::test_EnclosingClassProb() {
  CPPUNIT_FAIL("test_EnclosingClassProb not implemented");
}

void ReadClassTest::test_EnclosingReadProb() {
  CPPUNIT_FAIL("test_EnclosingClassProb not implemented");
}

void ReadClassTest::test_GetClassLogLikelihood() {
  CPPUNIT_FAIL("test_GetClassLogLikelihood not implemented");
}

void ReadClassTest::test_GetAlleleLogLikelihood() {
  CPPUNIT_FAIL("test_GetAlleleLogLikelihood not implemented");
}

