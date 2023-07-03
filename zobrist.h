#pragma once


uint64_t getHashKey(Board *boardObj);
void updatePieceHash(int sq ,uint64_t &hashKey,int piece);
void updateSideHash(uint64_t &hashkey);
void updateHashCastling(uint64_t &hashKey,int castlingRights);
void updateHashEnPassant(int enPassantSq,uint64_t &hashKey);
