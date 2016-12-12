//
//  StringPractice.hpp
//  CPP_Practice
//
//  Created by Sean on 12/12/2016.
//  Copyright © 2016 Sean. All rights reserved.
//

#ifndef StringPractice_hpp
#define StringPractice_hpp

#include <string>
#include "gtest.h"

TEST(StringTest, Storage) {
    std::string s1("123456");
    std::string s2 = s1;
    EXPECT_EQ(s1, s2);
    
    s1[0] = '6';
    EXPECT_EQ(s1, "623456");
    EXPECT_EQ(s2, "123456");

    EXPECT_NE(s2, s1);
}

#endif /* StringPractice_hpp */
