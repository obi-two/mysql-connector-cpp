/*
   Copyright 2009 - 2010 Sun Microsystems, Inc.  All rights reserved.

   The MySQL Connector/C++ is licensed under the terms of the GPL
   <http://www.gnu.org/licenses/old-licenses/gpl-2.0.html>, like most
   MySQL Connectors. There are special exceptions to the terms and
   conditions of the GPL as it is applied to this software, see the
   FLOSS License Exception
   <http://www.mysql.com/about/legal/licensing/foss-exception.html>.
 */

#include "../unit_fixture.h"
#include <iostream>
#include <climits>

/**
 * Example of a collection of tests
 *
 */

namespace testsuite
{
namespace classes
{

class preparedstatement : public unit_fixture
{
private:
  typedef unit_fixture super;
  bool createSP(std::string sp_code);

public:

  EXAMPLE_TEST_FIXTURE(preparedstatement)
  {
    TEST_CASE(crash);
    TEST_CASE(anonymousSelect);
    TEST_CASE(InsertSelectAllTypes);
    TEST_CASE(assortedSetType);
    TEST_CASE(setNull);
    TEST_CASE(checkClosed);
    TEST_CASE(getMetaData);
    TEST_CASE(callSP);
    TEST_CASE(callSPInOut);
    TEST_CASE(callSPWithPS);
    TEST_CASE(callSPMultiRes);
    TEST_CASE(getWarnings);
    TEST_CASE(blob);
    TEST_CASE(executeQuery);
  }

  /**
   * SELECT ' ', NULL as string
   */
  void anonymousSelect();

  /**
   * Loops over all kinds of column types and inserts/fetches a value
   */
  void InsertSelectAllTypes();

  /**
   * Loops over assorted column types and uses setXYZ to insert a value
   */
  void assortedSetType();

  /**
   * Loops over assorted column types and uses setXYZ to insert a value
   */
  void setNull();

  /**
   * Calling close()
   */
  void checkClosed();

  /**
   * Compare PS and Non-PS Metadata.
   */
  void getMetaData();

  /**
   * Calls a stored procedure
   */
  void callSP();

  /**
   * Calls a stored procedure with IN and OUT parameters
   */
  void callSPInOut();

  /**
   * Calls a stored procedure which contains a prepared statement
   */
  void callSPWithPS();

  /**
   * Calls a stored procedure which returns multiple result sets
   */
  void callSPMultiRes();

  /**
   * TODO - temporary to isolate a crash, remove after fix!
   */
  void crash();

  /**
   * Check get|clearWarnings()
   */
  void getWarnings();

  /**
   * Check BLOB/LOB handling
   */
  void blob();

  /**
   * Check executeQuery() and invalid fetch mode
   *
   * TODO - the test does focus on code coverage not functionality
   */
  void executeQuery();


};

REGISTER_FIXTURE(preparedstatement);
} /* namespace classes */
} /* namespace testsuite */
