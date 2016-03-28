#include <Matrix.hpp>
#include <catch.hpp>
#include <fstream>

SCENARIO("Matrix init", "[init]") {

	GIVEN("The number of rows and columns") {

		auto rows = 3;
		auto columns = 3;

		WHEN("Create instansce of Matrix") {

			Matrix matrix(rows, columns);

			THEN("The number of rows and columns must be preserved") {

				REQUIRE(matrix.lines() == rows);
				REQUIRE(matrix.columns() == columns);
			}
		}
	}
}
