#include <gtest/gtest.h>


class MainTest: public ::testing::Test{};

TEST_F( MainTest, test1){
  std::cout<<"good"<<std::endl;
}

int main(int argc, char **argv)
{
 testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}

