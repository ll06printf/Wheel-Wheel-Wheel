add_executable(hello_test hello_test.cpp)
target_link_libraries(hello_test GTest::gtest_main)

add_executable(ConstraintTest Snippet/ConstraintTest.cpp)
target_link_libraries(ConstraintTest
        TriWSnippet
        GTest::gtest_main
)

add_executable(NoConceptConstraintTest Snippet/NoConceptConstraintTest.cpp)
target_link_libraries(NoConceptConstraintTest
        TriWSnippet
        GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(
        hello_test
        ConstraintTest
        NoConceptConstraintTest
)
