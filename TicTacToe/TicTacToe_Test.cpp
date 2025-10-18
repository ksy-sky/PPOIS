#include <UnitTest++.h>
#include "TicTacToe.h"

TEST(TicTacToe_Move_Valid) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    CHECK_EQUAL('X', game.getValue(0, 0));
}

TEST(TicTacToe_Move_Invalid) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    CHECK_THROW(game.setMove(0, 0, 'O'), std::invalid_argument);
}

TEST(TicTacToe_Win_Row) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'X');
    game.setMove(0, 2, 'X');
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_Win_Column) {
    TicTacToe game(3);
    game.setMove(0, 0, 'O');
    game.setMove(1, 0, 'O');
    game.setMove(2, 0, 'O');
    CHECK(game.checkWin('O'));
}

TEST(TicTacToe_Win_Diagonal) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(1, 1, 'X');
    game.setMove(2, 2, 'X');
    CHECK(game.checkWin('X'));
}
TEST(TicTacToe_DiagonalWin_ComplexMoves) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(1, 0, 'O');
    game.setMove(1, 1, 'X');
    game.setMove(0, 1, 'O');
    game.setMove(2, 2, 'X');
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_Win_ReverseDiagonal) {
    TicTacToe game(3);
    game.setMove(0, 2, 'X');
    game.setMove(1, 1, 'X');
    game.setMove(2, 0, 'X');
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_FullBoard_NoWin) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'O');
    game.setMove(0, 2, 'X');
    game.setMove(1, 0, 'O');
    game.setMove(1, 1, 'X');
    game.setMove(1, 2, 'O');
    game.setMove(2, 0, 'O');
    game.setMove(2, 1, 'X');
    game.setMove(2, 2, 'O');
    CHECK(!game.checkWin('X'));
    CHECK(!game.checkWin('O'));
}
TEST(TicTacToe_FullBoard_EqualMoves) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'X');
    game.setMove(1, 0, 'X');
    game.setMove(1, 1, 'O');
    game.setMove(2, 0, 'O');
    game.setMove(2, 1, 'O');
    game.setMove(2, 2, 'X');
    CHECK(!game.checkWin('X'));
    CHECK(!game.checkWin('O'));
}
TEST(TicTacToe_CopyConstructor) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    TicTacToe gameCopy(game);
    CHECK_EQUAL('X', gameCopy.getValue(0, 0));
}
TEST(TicTacToe_InitialBoardState) {
    TicTacToe game(3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            CHECK_EQUAL(' ', game.getValue(i, j));
        }
    }
}
TEST(TicTacToe_AssignmentOperator) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    TicTacToe game2(3);
    game2 = game1;
    CHECK_EQUAL('X', game2.getValue(0, 0));
}

TEST(TicTacToe_GetValue_Empty) {
    TicTacToe game(3);
    CHECK_EQUAL(' ', game.getValue(1, 1));
}

TEST(TicTacToe_InvalidMove_OutOfBounds) {
    TicTacToe game(3);
    CHECK_THROW(game.setMove(-1, 0, 'X'), std::invalid_argument);
    CHECK_THROW(game.setMove(3, 0, 'X'), std::invalid_argument);
}

TEST(TicTacToe_ValidMove_InBounds) {
    TicTacToe game(3);
    bool exceptionThrown = false;
    try {
        game.setMove(0, 0, 'X');
    }
    catch (...) {
        exceptionThrown = true;
    }
    CHECK(!exceptionThrown);
}

TEST(TicTacToe_DiagonalWin_AfterMultipleMoves) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(1, 1, 'X');
    game.setMove(2, 2, 'X');
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_ColumnWin_AfterMultipleMoves) {
    TicTacToe game(3);
    game.setMove(0, 0, 'O');
    game.setMove(1, 0, 'O');
    game.setMove(2, 0, 'O');
    CHECK(game.checkWin('O'));
}

TEST(TicTacToe_RowWin_AfterMultipleMoves) {
    TicTacToe game(3);
    game.setMove(1, 0, 'X');
    game.setMove(1, 1, 'X');
    game.setMove(1, 2, 'X');
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_EmptyBoard_NoWin) {
    TicTacToe game(3);
    CHECK(!game.checkWin('X'));
    CHECK(!game.checkWin('O'));
}

TEST(TicTacToe_PlaceMark_DiagonalWin) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(1, 1, 'X');
    game.setMove(2, 2, 'X');
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_PlaceMark_ReverseDiagonalWin) {
    TicTacToe game(3);
    game.setMove(0, 2, 'O');
    game.setMove(1, 1, 'O');
    game.setMove(2, 0, 'O');
    CHECK(game.checkWin('O'));
}

TEST(TicTacToe_ColumnWin_Condition) {
    TicTacToe game(3);
    game.setMove(0, 1, 'X');
    game.setMove(1, 1, 'X');
    game.setMove(2, 1, 'X');
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_RowWin_Condition) {
    TicTacToe game(3);
    game.setMove(2, 0, 'O');
    game.setMove(2, 1, 'O');
    game.setMove(2, 2, 'O');
    CHECK(game.checkWin('O'));
}

TEST(TicTacToe_FullBoard_NoWin_AfterMultiplePlays) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'O');
    game.setMove(0, 2, 'X');
    game.setMove(1, 0, 'O');
    game.setMove(1, 1, 'X');
    game.setMove(1, 2, 'O');
    game.setMove(2, 0, 'O');
    game.setMove(2, 1, 'X');
    game.setMove(2, 2, 'O');
    CHECK(!game.checkWin('X'));
    CHECK(!game.checkWin('O'));
}

TEST(TicTacToe_SingleMove_Win) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    CHECK(!game.checkWin('X'));
}


TEST(TicTacToe_PlaceMark_SwitchPlayers) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(1, 1, 'O');
    CHECK_EQUAL('X', game.getValue(0, 0));
    CHECK_EQUAL('O', game.getValue(1, 1));
}
TEST(TicTacToe_PartialWin) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'X');
    CHECK(!game.checkWin('X')); 
    game.setMove(0, 2, 'X');
    CHECK(game.checkWin('X'));
}
TEST(TicTacToe_Move_AfterWin) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'X');
    game.setMove(0, 2, 'X');
    CHECK(game.checkWin('X'));
    CHECK_THROW(game.setMove(1, 1, 'O'), std::invalid_argument); 
}

TEST(TicTacToe_DifferentBoardSizes) {
    TicTacToe game4(4);
    game4.setMove(0, 0, 'X');
    game4.setMove(1, 1, 'O');
    game4.setMove(2, 2, 'X');
    game4.setMove(3, 3, 'O');
try {
        game4.setMove(0, 1, 'X'); 
        CHECK(true); 
    } catch (...) {
        CHECK(false); 
    }
    CHECK_EQUAL('O', game4.getValue(3, 3));
}

TEST(TicTacToe_LargeBoardWin) {
    TicTacToe game(5);
    for (int i = 0; i < 5; i++) {
        game.setMove(2, i, 'X');
    }
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_SingleCellBoard) {
    TicTacToe game(1);
    game.setMove(0, 0, 'X');
    CHECK(game.checkWin('X'));
    CHECK_THROW(game.setMove(0, 0, 'O'), std::invalid_argument);
}

TEST(TicTacToe_BoardBoundaries) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 2, 'O');
    game.setMove(2, 0, 'X');
    game.setMove(2, 2, 'O');
    
    CHECK_EQUAL('X', game.getValue(0, 0));
    CHECK_EQUAL('O', game.getValue(0, 2));
    CHECK_EQUAL('X', game.getValue(2, 0));
    CHECK_EQUAL('O', game.getValue(2, 2));
}

TEST(TicTacToe_CenterMove) {
    TicTacToe game(3);
    game.setMove(1, 1, 'X');
    CHECK_EQUAL('X', game.getValue(1, 1));
CHECK_THROW(game.setMove(1, 1, 'O'), std::invalid_argument);
}

TEST(TicTacToe_PlayerSwitching_Comprehensive) {
    TicTacToe game(3);
    
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'O');
    game.setMove(0, 2, 'X');
    game.setMove(1, 0, 'O');
    
    CHECK_EQUAL('X', game.getValue(0, 0));
    CHECK_EQUAL('O', game.getValue(0, 1));
    CHECK_EQUAL('X', game.getValue(0, 2));
    CHECK_EQUAL('O', game.getValue(1, 0));
}

TEST(TicTacToe_SamePlayerMultipleMoves) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(1, 0, 'X'); 
    game.setMove(2, 0, 'X');
    
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_CopyConstructor_DeepCopy) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    game1.setMove(1, 1, 'O');
    
    TicTacToe game2(game1);
    
    CHECK_EQUAL('X', game2.getValue(0, 0));
    CHECK_EQUAL('O', game2.getValue(1, 1));
    
    game1.setMove(2, 2, 'X');
    CHECK_EQUAL(' ', game2.getValue(2, 2));
}

TEST(TicTacToe_AssignmentOperator_DeepCopy) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    game1.setMove(1, 1, 'O');
    
    TicTacToe game2(3);
    game2 = game1;
    
    CHECK_EQUAL('X', game2.getValue(0, 0));
    CHECK_EQUAL('O', game2.getValue(1, 1));
    
    game1.setMove(2, 2, 'X');
    CHECK_EQUAL(' ', game2.getValue(2, 2));
}

TEST(TicTacToe_WinAfterManyMoves) {
    TicTacToe game(3);
    game.setMove(0, 1, 'X');
    game.setMove(1, 0, 'O');
    game.setMove(1, 1, 'X');
    game.setMove(2, 0, 'O');
    game.setMove(0, 0, 'X');
    game.setMove(2, 2, 'O');
    game.setMove(0, 2, 'X');
    CHECK(game.checkWin('X'));
}
TEST(TicTacToe_CopyConstructor_Complex) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    game1.setMove(1, 1, 'O');
    game1.setMove(2, 2, 'X');
    
    TicTacToe game2(game1);
    CHECK_EQUAL('X', game2.getValue(0, 0));
    CHECK_EQUAL('O', game2.getValue(1, 1));
    CHECK_EQUAL('X', game2.getValue(2, 2));
}

TEST(TicTacToe_Assignment_Complex) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    game1.setMove(1, 1, 'O');
    
    TicTacToe game2(3);
    game2 = game1;
    CHECK_EQUAL('X', game2.getValue(0, 0));
    CHECK_EQUAL('O', game2.getValue(1, 1));
}
TEST(TicTacToe_Stream_EmptyBoard) {
    TicTacToe game(3);
    std::ostringstream oss;
    oss << game;
    std::string output = oss.str();
    CHECK(output.find(' ') != std::string::npos);
}

TEST(TicTacToe_Stream_InputWithWin) {
    TicTacToe game(3);
    std::istringstream iss("X X X O O     ");
    iss >> game;
    CHECK(game.checkWin('X'));
}
TEST(TicTacToe_OperatorIndex_WriteRead) {
    TicTacToe game(3);
    std::pair<int, int> pos = {1, 1};
    game[pos] = 'X';
    CHECK_EQUAL('X', game[pos]);
    
    game[{0, 0}] = 'O';
    CHECK_EQUAL('O', game.getValue(0, 0));
}

TEST(TicTacToe_SelfAssignment) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game = game; 
    CHECK_EQUAL('X', game.getValue(0, 0));
}
TEST(TicTacToe_AllWinCombinations) {
    std::vector<std::vector<std::pair<int, int>>> winCombinations = {
        {{0,0}, {0,1}, {0,2}},
        {{1,0}, {1,1}, {1,2}},
        {{2,0}, {2,1}, {2,2}},
        {{0,0}, {1,0}, {2,0}},
        {{0,1}, {1,1}, {2,1}},
        {{0,2}, {1,2}, {2,2}},
        {{0,0}, {1,1}, {2,2}},
        {{0,2}, {1,1}, {2,0}}
    };
    
    for (const auto& combination : winCombinations) {
        TicTacToe game(3);
        for (const auto& pos : combination) {
            game.setMove(pos.first, pos.second, 'X');
        }
        CHECK(game.checkWin('X'));
    }
}

TEST(TicTacToe_ValidPlayers) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'O');
    CHECK_EQUAL('X', game.getValue(0, 0));
    CHECK_EQUAL('O', game.getValue(0, 1));
}

TEST(TicTacToe_SmallBoard_Win) {
    TicTacToe game(2);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'X'); 
    CHECK(game.checkWin('X'));
}

TEST(TicTacToe_LargeBoard_Partial) {
    TicTacToe game(4);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'O');
    game.setMove(1, 0, 'O');
    game.setMove(1, 1, 'X');
    
    CHECK(!game.checkWin('X'));
    CHECK(!game.checkWin('O'));
}

TEST(TicTacToe_CopyConstructor_WithPartialGame) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    game1.setMove(1, 1, 'O');
    
    TicTacToe game2(game1);
    CHECK_EQUAL('X', game2.getValue(0, 0));
    CHECK_EQUAL('O', game2.getValue(1, 1));
    CHECK_EQUAL(' ', game2.getValue(2, 2)); 
}

TEST(TicTacToe_Assignment_WithPartialGame) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    game1.setMove(1, 1, 'O');
    
    TicTacToe game2(3);
    game2 = game1;
    CHECK_EQUAL('X', game2.getValue(0, 0));
    CHECK_EQUAL('O', game2.getValue(1, 1));
}

TEST(TicTacToe_SelfAssignment_Safe) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(1, 1, 'O');
    
    TicTacToe& ref = game;
    game = ref;
    
    CHECK_EQUAL('X', game.getValue(0, 0));
    CHECK_EQUAL('O', game.getValue(1, 1));
}

TEST(TicTacToe_OperatorIndex_ReadWrite) {
    TicTacToe game(3);
    
    std::pair<int, int> pos1 = std::make_pair(0, 0);
    std::pair<int, int> pos2 = std::make_pair(1, 1);
    std::pair<int, int> pos3 = std::make_pair(2, 2);
    
    game[pos1] = 'X';
    game[pos2] = 'O';
    game[pos3] = 'X';
    
    CHECK_EQUAL('X', game[pos1]);
    CHECK_EQUAL('O', game[pos2]);
    CHECK_EQUAL('X', game[pos3]);
}

TEST(TicTacToe_CheckWin_InvalidPlayer) {
    TicTacToe game(3);
    CHECK(!game.checkWin('Z'));
    CHECK(!game.checkWin('A'));
    CHECK(!game.checkWin('1'));
}

TEST(TicTacToe_AlmostWin_Scenario) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'X');
    CHECK(!game.checkWin('X'));
    
    game.setMove(0, 2, 'O');
    CHECK(!game.checkWin('X'));
}

TEST(TicTacToe_DifferentBoardSizes_Corners) {
    TicTacToe game(4);
    game.setMove(0, 0, 'X');
    game.setMove(0, 3, 'O');
    game.setMove(3, 0, 'X');
    game.setMove(3, 3, 'O');
    
    CHECK_EQUAL('X', game.getValue(0, 0));
    CHECK_EQUAL('O', game.getValue(0, 3));
    CHECK_EQUAL('X', game.getValue(3, 0));
    CHECK_EQUAL('O', game.getValue(3, 3));
}

TEST(TicTacToe_GameOver_StatePreserved) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    game.setMove(0, 1, 'X');
    game.setMove(0, 2, 'X'); 
    CHECK_EQUAL('X', game.getValue(0, 0));
    CHECK_EQUAL('X', game.getValue(0, 1));
    CHECK_EQUAL('X', game.getValue(0, 2));
    
    CHECK_THROW(game.setMove(1, 1, 'O'), std::invalid_argument);
}

TEST(TicTacToe_Stream_EmptyBoardOutput) {
    TicTacToe game(3);
    std::ostringstream oss;
    oss << game;
    std::string output = oss.str();
    
    CHECK(output.find(" | ") != std::string::npos);
    CHECK(output.find("-") != std::string::npos);
}


TEST(TicTacToe_OperatorIndex_MultipleAccess) {
    TicTacToe game(3);
    
    std::pair<int, int> pos = {1, 1};
    game[pos] = 'X';
    game[pos] = 'O'; 
    game[pos] = 'X'; 
    
    CHECK_EQUAL('X', game[pos]);
    CHECK_EQUAL('X', game.getValue(1, 1));
}

TEST(TicTacToe_CopyConstructor_EmptyBoard) {
    TicTacToe game1(3); 
    TicTacToe game2(game1);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            CHECK_EQUAL(' ', game2.getValue(i, j));
        }
    }
}

TEST(TicTacToe_Assignment_EmptyToEmpty) {
    TicTacToe game1(3); 
    TicTacToe game2(3); 
    game2 = game1;     
    CHECK_EQUAL(' ', game2.getValue(1, 1));
}


TEST(TicTacToe_ComplexWin_AllDirections) {
    struct WinScenario {
        std::vector<std::pair<int, int>> moves;
        char player;
    };
    
    std::vector<WinScenario> scenarios = {
        {{{0,0}, {0,1}, {0,2}}, 'X'},
        {{{1,0}, {1,1}, {1,2}}, 'O'},
        {{{2,0}, {2,1}, {2,2}}, 'X'},
        {{{0,0}, {1,0}, {2,0}}, 'O'},
        {{{0,1}, {1,1}, {2,1}}, 'X'},
        {{{0,2}, {1,2}, {2,2}}, 'O'},
        {{{0,0}, {1,1}, {2,2}}, 'X'},
        {{{0,2}, {1,1}, {2,0}}, 'O'}
    };
    
    for (const auto& scenario : scenarios) {
        TicTacToe game(3);
        for (const auto& move : scenario.moves) {
            game.setMove(move.first, move.second, scenario.player);
        }
        CHECK(game.checkWin(scenario.player));
    }
}

TEST(TicTacToe_BoardState_AfterMultipleOperations) {
    TicTacToe game(3);
    
    game.setMove(0, 0, 'X');
    game[{1, 1}] = 'O';
    
    TicTacToe game2 = game;
    
    CHECK_EQUAL('X', game.getValue(0, 0));
    CHECK_EQUAL('O', game.getValue(1, 1));
    CHECK_EQUAL('X', game2.getValue(0, 0));
    CHECK_EQUAL('O', game2.getValue(1, 1));
    
    std::ostringstream oss;
    oss << game;
    CHECK(!oss.str().empty());
}

TEST(TicTacToe_EdgeCoordinates) {
    TicTacToe game(3);
    
    game.setMove(0, 0, 'X'); 
    game.setMove(0, 2, 'O');  
    game.setMove(2, 0, 'X'); 
    game.setMove(2, 2, 'O');    
    CHECK_EQUAL('X', game.getValue(0, 0));
    CHECK_EQUAL('O', game.getValue(0, 2));
    CHECK_EQUAL('X', game.getValue(2, 0));
    CHECK_EQUAL('O', game.getValue(2, 2));
}

TEST(TicTacToe_OperatorIndex_DifferentPositions) {
    TicTacToe game(3);
    
    std::pair<int, int> pos1 = {0, 1};
    std::pair<int, int> pos2 = {1, 0};
    std::pair<int, int> pos3 = {2, 2};
    
    game[pos1] = 'X';
    game[pos2] = 'O';
    game[pos3] = 'X';
    
    char val1 = game[pos1];
    char val2 = game[pos2];
    char val3 = game[pos3];
    
    CHECK_EQUAL('X', val1);
    CHECK_EQUAL('O', val2);
    CHECK_EQUAL('X', val3);
}
TEST(TicTacToe_Copy_ModifyOriginal) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    
    TicTacToe game2(game1);
    
    game1.setMove(1, 1, 'O');
    
    CHECK_EQUAL('X', game2.getValue(0, 0));
    CHECK_EQUAL(' ', game2.getValue(1, 1)); 
}

TEST(TicTacToe_Assignment_ModifySource) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    
    TicTacToe game2(3);
    game2 = game1;
    
    game1.setMove(1, 1, 'O');
    
    CHECK_EQUAL('X', game2.getValue(0, 0));
    CHECK_EQUAL(' ', game2.getValue(1, 1)); 
}

TEST(TicTacToe_CheckWin_EmptyBoard) {
    TicTacToe game(3);
    CHECK(!game.checkWin('X'));
    CHECK(!game.checkWin('O'));
    CHECK(!game.checkWin('Z')); 
}

TEST(TicTacToe_MultipleGames_Independent) {
    TicTacToe game1(3);
    TicTacToe game2(3);
    
    game1.setMove(0, 0, 'X');
    game2.setMove(1, 1, 'O');
    
    CHECK_EQUAL('X', game1.getValue(0, 0));
    CHECK_EQUAL(' ', game1.getValue(1, 1));
    CHECK_EQUAL('O', game2.getValue(1, 1));
    CHECK_EQUAL(' ', game2.getValue(0, 0));
}

TEST(TicTacToe_OperatorEqual_EmptyBoards) {
    TicTacToe game1(3);
    TicTacToe game2(3);
    CHECK(game1 == game2);
    CHECK(!(game1 != game2));
}

TEST(TicTacToe_OperatorEqual_SameMoves) {
    TicTacToe game1(3);
    TicTacToe game2(3);
    
    game1.setMove(0, 0, 'X');
    game1.setMove(1, 1, 'O');
    
    game2.setMove(0, 0, 'X');
    game2.setMove(1, 1, 'O');
    
    CHECK(game1 == game2);
    CHECK(!(game1 != game2));
}

TEST(TicTacToe_OperatorNotEqual_DifferentMoves) {
    TicTacToe game1(3);
    TicTacToe game2(3);
    
    game1.setMove(0, 0, 'X');
    game2.setMove(0, 0, 'O'); 
    
    CHECK(game1 != game2);
    CHECK(!(game1 == game2));
}

TEST(TicTacToe_OperatorNotEqual_DifferentPositions) {
    TicTacToe game1(3);
    TicTacToe game2(3);
    
    game1.setMove(0, 0, 'X');
    game2.setMove(1, 1, 'X');     
    CHECK(game1 != game2);
    CHECK(!(game1 == game2));
}

TEST(TicTacToe_OperatorEqual_AfterWin) {
    TicTacToe game1(3);
    TicTacToe game2(3);
    game1.setMove(0, 0, 'X');
    game1.setMove(0, 1, 'X');
    game1.setMove(0, 2, 'X');
    
    game2.setMove(0, 0, 'X');
    game2.setMove(0, 1, 'X');
    game2.setMove(0, 2, 'X');
    
    CHECK(game1 == game2);
    CHECK(!(game1 != game2));
}

TEST(TicTacToe_OperatorNotEqual_DifferentGameStates) {
    TicTacToe game1(3);
    TicTacToe game2(3);
    
    game1.setMove(0, 0, 'X');
    game1.setMove(0, 1, 'X');
    game1.setMove(0, 2, 'X');
}

TEST(TicTacToe_OperatorNotEqual_DifferentSizes) {
    TicTacToe game1(3);
    TicTacToe game2(4);
    
    CHECK(game1 != game2);
    CHECK(!(game1 == game2));
}

TEST(TicTacToe_OperatorEqual_CopyConstructor) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    game1.setMove(1, 1, 'O');
    
    TicTacToe game2(game1); 
    CHECK(game1 == game2);
    CHECK(!(game1 != game2));
}

TEST(TicTacToe_OperatorEqual_Assignment) {
    TicTacToe game1(3);
    game1.setMove(0, 0, 'X');
    game1.setMove(1, 1, 'O');
    
    TicTacToe game2(3);
    game2 = game1;     
    CHECK(game1 == game2);
    CHECK(!(game1 != game2));
}

TEST(TicTacToe_OperatorEqual_SelfComparison) {
    TicTacToe game(3);
    game.setMove(0, 0, 'X');
    
    CHECK(game == game);
    CHECK(!(game != game));
}
TEST(TicTacToe_OperatorEqual_ComplexBoard) {
    TicTacToe game1(3);
    TicTacToe game2(3);
    
    char players[3][3] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'O', 'X', 'O'}  
    };
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            game1.setMove(i, j, players[i][j]);
            game2.setMove(i, j, players[i][j]);
        }
    }
    
    CHECK(game1 == game2);
    CHECK(!(game1 != game2));
}

int main(int argc, char** argv) {
    return UnitTest::RunAllTests();
}

