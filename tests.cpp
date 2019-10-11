// written with Catch2
// https://github.com/catchorg/Catch2

#include "catch.hpp"
#include "Game.h"

TEST_CASE("field create test 3", "[1]"){
    Game *tester = new Game(3);
    CHECK(tester->getPoint(0, 0) == 0);
    CHECK(tester->getPoint(0, 1) == 0);
    CHECK(tester->getPoint(0, 2) == 0);
    CHECK(tester->getPoint(1, 0) == 0);
    CHECK(tester->getPoint(1, 1) == 0);
    CHECK(tester->getPoint(1, 2) == 0);
    CHECK(tester->getPoint(2, 0) == 0);
    CHECK(tester->getPoint(2, 1) == 0);
    CHECK(tester->getPoint(2, 2) == 0);
    delete  tester;
}

TEST_CASE("field create test 2", "[2]"){
    Game *tester = new Game(3);
    CHECK(tester->getPoint(0, 0) == 0);
    CHECK(tester->getPoint(0, 1) == 0);
    CHECK(tester->getPoint(1, 1) == 0);
    CHECK(tester->getPoint(1, 0) == 0);
    delete  tester;
}

TEST_CASE("check for krestiki", "[3]"){
    Game *tester = new Game(3);
    tester->setValue(0, 1, 1);
    tester->setValue(0, 0, 1);
    tester->setValue(0, 2, 1);
    REQUIRE(tester->checkWin() == 1);
    delete  tester;
}

TEST_CASE("check for tie", "[4]"){
    Game *tester = new Game(3);
    tester->setValue(0, 0, 1);
    tester->setValue(0, 1, 2);
    tester->setValue(0, 2, 1);
    tester->setValue(1, 1, 2);
    tester->setValue(1, 0, 1);
    tester->setValue(1, 2, 2);
    tester->setValue(2, 1, 1);
    tester->setValue(2, 0, 2);
    tester->setValue(2, 2, 1);
    REQUIRE(tester->checkWin() == 3);
    delete  tester;
}

TEST_CASE("check for krestiki column", "[5]"){
    Game *tester = new Game(3);
    tester->setValue(0, 1, 1);
    tester->setValue(1, 1, 1);
    tester->setValue(2, 1, 1);
    REQUIRE(tester->checkWin() == 1);
    delete  tester;
}

TEST_CASE("check for krestiki diagonal", "[6]"){
    Game *tester = new Game(3);
    tester->setValue(0, 0, 1);
    tester->setValue(1, 1, 1);
    tester->setValue(2, 2, 1);
    REQUIRE(tester->checkWin() == 1);
    delete  tester;
}

TEST_CASE("check for noliki", "[7]"){
    Game *tester = new Game(3);
    tester->setValue(0, 1, 2);
    tester->setValue(0, 0, 2);
    tester->setValue(0, 2, 2);
    REQUIRE(tester->checkWin() == 2);
    delete  tester;
}

TEST_CASE("check for noliki column", "[8]"){
    Game *tester = new Game(3);
    tester->setValue(0, 1, 2);
    tester->setValue(1, 1, 2);
    tester->setValue(2, 1, 2);
    REQUIRE(tester->checkWin() == 2);
    delete  tester;
}

TEST_CASE("check for noliki diagonal", "[9]"){
    Game *tester = new Game(3);
    tester->setValue(0, 0, 2);
    tester->setValue(1, 1, 2);
    tester->setValue(2, 2, 2);
    REQUIRE(tester->checkWin() == 2);
    delete  tester;
}
TEST_CASE("krest 2x2", "[10]"){
    Game *tester = new Game(2);
    tester->setValue(0, 0, 1);
    tester->setValue(1, 1, 1);
    tester->setValue(0, 1, 2);
    REQUIRE(tester->checkWin() == 1);
    delete  tester;
}

TEST_CASE("krest  2x2 column", "[11]"){
    Game *tester = new Game(2);
    tester->setValue(0, 0, 2);
    tester->setValue(1, 1, 1);
    tester->setValue(0, 1, 1);
    REQUIRE(tester->checkWin() == 1);
    delete  tester;
}

TEST_CASE("nolik 2x2", "[12]"){
    Game *tester = new Game(2);
    tester->setValue(0, 0, 2);
    tester->setValue(1, 1, 2);
    tester->setValue(0, 1, 1);
    REQUIRE(tester->checkWin() == 2);
    delete  tester;
}

TEST_CASE("nolik  2x2 column", "[13]"){
    Game *tester = new Game(2);
    tester->setValue(0, 0, 1);
    tester->setValue(1, 1, 2);
    tester->setValue(0, 1, 2);
    REQUIRE(tester->checkWin() == 2);
    delete  tester;
}

TEST_CASE("krestik 4x4", "[14]"){
    Game *tester = new Game(4);
    tester->setValue(0, 0, 1);
    tester->setValue(0, 1, 1);
    tester->setValue(0, 2, 1);
    tester->setValue(0, 3, 1);
    tester->setValue(1, 1, 2);
    tester->setValue(2, 1, 2);
    tester->setValue(3, 1, 2);
    REQUIRE(tester->checkWin() == 1);
    delete tester;
}

TEST_CASE("krestik diagonal 4x4", "[15]"){
    Game *tester = new Game(4);
    tester->setValue(0, 0, 1);
    tester->setValue(1, 1, 1);
    tester->setValue(2, 2, 1);
    tester->setValue(3, 3, 1);
    tester->setValue(1, 2, 2);
    tester->setValue(2, 1, 2);
    tester->setValue(3, 1, 2);
    REQUIRE(tester->checkWin() == 1);
    delete tester;
}

TEST_CASE("tie 4x4", "[16]"){
    Game *tester = new Game(4);
    tester->setValue(0, 0, 1);
    tester->setValue(0, 1, 2);
    tester->setValue(0, 2, 1);
    tester->setValue(0, 3, 2);
    tester->setValue(1, 0, 2);
    tester->setValue(1, 1, 1);
    tester->setValue(1, 2, 2);
    tester->setValue(1, 3, 1);
    tester->setValue(2, 0, 1);
    tester->setValue(2, 1, 2);
    tester->setValue(2, 2, 1);
    tester->setValue(2, 3, 2);
    tester->setValue(3, 0, 2);
    tester->setValue(3, 1, 2);
    tester->setValue(3, 2, 1);
    tester->setValue(3, 3, 2);
    REQUIRE(tester->checkWin() == 3);
    delete tester;
}

TEST_CASE("nolik 4x4", "[17]"){
    Game *tester = new Game(4);
    tester->setValue(0, 0, 2);
    tester->setValue(0, 1, 2);
    tester->setValue(0, 2, 2);
    tester->setValue(0, 3, 2);
    tester->setValue(1, 1, 1);
    tester->setValue(2, 1, 1);
    tester->setValue(3, 1, 1);
    REQUIRE(tester->checkWin() == 2);
    delete tester;
}

TEST_CASE("nolik diagonal 4x4", "[18]"){
    Game *tester = new Game(4);
    tester->setValue(0, 0, 2);
    tester->setValue(1, 1, 2);
    tester->setValue(2, 2, 2);
    tester->setValue(3, 3, 2);
    tester->setValue(1, 2, 1);
    tester->setValue(2, 1, 1);
    tester->setValue(3, 1, 1);
    REQUIRE(tester->checkWin() == 2);
    delete tester;
}