#include <iostream>

//----------------------------------------------------------------------
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN	/*! Use if doctest with its own main function*/
#include "doctest.h"		// Get the last version online
//----------------------------------------------------------------------

#include "Dummy.hpp"
//----------------------------------------------------------------------
TEST_CASE("1. Signal Class (virtual) - Concrete class = Dummy - Basic accessors and low-level Signal parameters") {
	Dummy	myDummy{};
	float 	testValue{5.0};
	
	CHECK(myDummy.getValue() == doctest::Approx(DummydefaultValue));
	
	myDummy.setValue(testValue);
	CHECK(myDummy.getValue() == doctest::Approx(testValue));
	
}
//----------------------------------------------------------------------
TEST_CASE("2. Signal Class (virtual) - Concrete class = Dummy / default value / non const obj - generate function") {
	Dummy	myDummy{};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(DummydefaultValue));
	
	std::string_view	FileName{defaultFileName};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1800};
	
	unsigned int FileSize = myDummy.generate();
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
//----------------------------------------------------------------------
TEST_CASE("3. Signal Class (virtual) - Concrete class = Dummy / default value / const obj - generate function") {
	const Dummy		myDummy{};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(DummydefaultValue));
	
	std::string_view	FileName{defaultFileName};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1800};
	
	unsigned int FileSize = myDummy.generate();
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
//----------------------------------------------------------------------
TEST_CASE("4. Signal Class (virtual) - Concrete class = Dummy / Value = 12 / non const obj - generate function") {
	
	DummyParam 	dc12{12.0};
	
	Dummy	myDummy{dc12};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(dc12.value));
	
	std::string_view	FileName{defaultFileName};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1900};
	
	unsigned int FileSize = myDummy.generate();
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
//----------------------------------------------------------------------
TEST_CASE("5. Signal Class (virtual) - Concrete class = Dummy / Value = 12 / const obj - generate function") {
	
	DummyParam 	dc12{12.0};
	
	const Dummy	myDummy{dc12};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(dc12.value));
	
	std::string_view	FileName{defaultFileName};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1900};
	
	unsigned int FileSize = myDummy.generate();
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
//----------------------------------------------------------------------
TEST_CASE("6. Signal Class (virtual) - Concrete class = Dummy / Value = 12 / non const obj - generate function - FileName = dummy.data") {
	
	DummyParam 	dc12{12.0};
	
	Dummy	myDummy{dc12};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(dc12.value));
	
	std::string_view	FileName{"./dummy.data"};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1900};
	
	unsigned int FileSize = myDummy.generate(FileName);
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
//----------------------------------------------------------------------
TEST_CASE("7. Signal Class (virtual) - Concrete class = Dummy / Value = 12 / const obj - generate function - FileName = dummy.data") {
	
	DummyParam 	dc12{12.0};
	
	const Dummy	myDummy{dc12};
		
	REQUIRE(myDummy.getValue() == doctest::Approx(dc12.value));
	
	std::string_view	FileName{"./dummy.data"};
	std::filesystem::remove(FileName);
	REQUIRE(std::filesystem::exists(FileName) == false);
	unsigned int 		expectedSize{1900};
	
	unsigned int FileSize = myDummy.generate(FileName);
	
	CHECK(FileSize == expectedSize);
	CHECK(std::filesystem::exists(FileName) == true);
	CHECK(std::filesystem::is_regular_file(FileName) == true);
	CHECK(std::filesystem::file_size(FileName) == expectedSize);
}
//----------------------------------------------------------------------
