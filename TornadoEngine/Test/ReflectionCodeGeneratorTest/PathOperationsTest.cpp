/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
������� ������ ���������
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "PathOperations.h"
#include <filesystem>


TEST(PathOperation, AbsByRel)
{
    auto currentPath = std::filesystem::canonical(".");
    auto currentPathStr = currentPath.string();

    std::string rel = "\\..\\";

    auto abs = TPathOperations::CalculatePathBy(currentPathStr, rel);
    ASSERT_EQ(abs.empty(), false);

    auto parentPath = currentPath.parent_path().string();

    ASSERT_EQ(abs, parentPath);
}

TEST(PathOperation, IncorrectRel)
{
    auto currentPath = std::filesystem::canonical(".");
    auto currentPathStr = currentPath.string();

    std::string rel = "\\..\\ASDF";

    auto abs = TPathOperations::CalculatePathBy(currentPathStr, rel);
    ASSERT_EQ(abs.empty(), true);
}

TEST(PathOperation, AbsByAbs)
{
    auto currentPath = std::filesystem::canonical(".");
    auto currentPathStr = currentPath.string();

    std::string abs = currentPathStr;

    auto absByAbs = TPathOperations::CalculatePathBy(currentPathStr, abs);
    ASSERT_EQ(abs.empty(), false);
    ASSERT_EQ(abs, absByAbs);
}

TEST(PathOperation, IncorrectAll)
{
    std::string abs = "asda";
    std::string rel = "adad";

    auto absByRel = TPathOperations::CalculatePathBy(abs, rel);
    ASSERT_EQ(absByRel.empty(), true);
}

TEST(PathOperation, IncorrectAbs)
{
    auto currentPathStr = "asdad";

    std::string rel = "\\.\\";

    auto abs = TPathOperations::CalculatePathBy(currentPathStr, rel);
    ASSERT_EQ(abs.empty(), true);
}