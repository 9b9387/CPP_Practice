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
#include <iostream>
#include "gtest.h"

using namespace std;

TEST(StringTest, Storage) {
    std::string s1("123456");
    std::string s2 = s1;
    EXPECT_EQ(s1, s2);
    
    s1[0] = '6';
    EXPECT_EQ(s1, "623456");
    EXPECT_EQ(s2, "123456");

    EXPECT_NE(s2, s1);
}

TEST(StringTest, Init) {
    std::string imBlack;
    EXPECT_EQ(imBlack, "");
    std::string s1("I'm a string");
    EXPECT_EQ(s1, "I'm a string");
    std::string s2 = "string2";
    EXPECT_EQ(s2, "string2");
    std::string s3(s2);
    EXPECT_EQ(s3, "string2");
    EXPECT_EQ(s2, s2);
    std::string s4(s1.begin(), s1.end());
    EXPECT_EQ(s4, s1);
    std::string s5(s1.begin() + 6, s1.end());
    EXPECT_EQ(s5, "string");
    std::string s6(5, 'a');
    EXPECT_EQ(s6, "aaaaa");

}

TEST(StringTest, substr) {
    std::string s1("What is the sound of one clam napping?");
    std::string s2(s1, 8, 3);
    EXPECT_EQ(s2, "the");
    EXPECT_EQ(s1.substr(8, 3), s2);
    EXPECT_EQ(s1.substr(), s1);
}

TEST(StringTest, append) {
    string s1 = "Hello";
    EXPECT_EQ(s1.size(), 5);

    string s2 = s1.append(" World");
    EXPECT_EQ(s2, "Hello World");
    EXPECT_EQ(s2, s1);
    EXPECT_EQ(s1.size(), 11);
    
    string s3;
    EXPECT_EQ(s3.capacity(), 0);
    s3.reserve(1000);
    EXPECT_EQ(s3.capacity(), 1000);
    s3 = "Hello";
    s3.resize(4);
    EXPECT_EQ(s3, "Hell");
    s3.resize(10, 'o');
    EXPECT_EQ(s3, "Helloooooo");
    EXPECT_EQ(s3.capacity(), 1000);
}

TEST(StringTest, replace) {
    string s("A piece of text");
    string tag("$tag$");
    s.insert(8, tag + ' ');
    EXPECT_EQ(s, "A piece $tag$ of text");
    
    unsigned long start = s.find(tag);
    EXPECT_EQ(start, 8);
    
    s.replace(start, tag.size(), "hello there");
    EXPECT_EQ(s, "A piece hello there of text");
    
    unsigned long pos1 = s.find("there", 0);
    EXPECT_EQ(pos1, 14);

    unsigned long pos2 = s.find("asdfa", 0);
    EXPECT_EQ(pos2, string::npos);

    s.replace(pos1, 5, "here");
    EXPECT_EQ(s, "A piece hello here of text");

}

TEST(StringTest, erase) {
    string s = "Hello String";
    s.erase(0, 6);
    EXPECT_EQ(s, "String");
    
    s.erase();
    EXPECT_EQ(s, "");
}

TEST(StringTest, compare) {
    string first("This");
    string second("That");
    
    EXPECT_EQ(first.compare(first), 0);
    EXPECT_EQ(first.compare(second) > 0, true);
    
}

#endif /* StringPractice_hpp */
