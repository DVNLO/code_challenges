/*
The following is a solution to leetcode prompt 999 available captures rook.
My solution iteratively searches for an existant rook, store's it's position
and then iterates from the position along the northward, southward, westward,
and eastward axis until a non-empty character or boundary is found. If the 
non-empty character is a BLACK_PAWN, the capture count is incremented, 
otherwise the iteration along this axis is halted. No driver provided.
Author: Dan Vyenielo
Original prompt: https://leetcode.com/problems/available-captures-for-rook/
*/

#include <vector>

using namespace std;

class Solution {
private:
	static constexpr char WHITE_ROOK{ 'R' };
	static constexpr char EMPTY{ '.' };
	static constexpr char WHITE_BISHOP{ 'B' };
	static constexpr char BLACK_PAWN{ 'p' };

public:
	int numRookCaptures(vector<vector<char>>& board) {
		size_t const rows = board.size();
		if (!rows)
		{
			return 0;
		}
		size_t const & cols = rows; // invariant

		int num_pawns_captured{ 0 };

		std::pair<size_t, size_t> rook_position;
		for (size_t row = 0; row < rows; ++row)
		{
			for (size_t col = 0; col < cols; ++col)
			{
				if (board[row][col] == WHITE_ROOK)
				{
					rook_position.first = row;
					rook_position.second = col;
				}
			}
		}
		for (int row = rook_position.first - 1; row >= 0; --row) // northward
		{
			if (board[row][rook_position.second] != EMPTY)
			{
				if (board[row][rook_position.second] == BLACK_PAWN)
				{
					++num_pawns_captured;
				}
				break;
			}
		}
		for (int row = rook_position.first + 1; row < rows; ++row) // southward
		{
			if (board[row][rook_position.second] != EMPTY)
			{
				if (board[row][rook_position.second] == BLACK_PAWN)
				{
					++num_pawns_captured;
				}
				break;
			}
		}
		for (int col = rook_position.second - 1; col >= 0; --col) // westward
		{
			if (board[rook_position.first][col] != EMPTY)
			{
				if (board[rook_position.first][col] == BLACK_PAWN)
				{
					++num_pawns_captured;
				}
				break;
			}
		}
		for (int col = rook_position.second + 1; col < cols; ++col) // eastward
		{
			if (board[rook_position.first][col] != EMPTY)
			{
				if (board[rook_position.first][col] == BLACK_PAWN)
				{
					++num_pawns_captured;
				}
				break;
			}
		}
		return num_pawns_captured;
	}
};