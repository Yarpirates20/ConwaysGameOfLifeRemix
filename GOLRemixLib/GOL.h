#pragma once
#include "pch.h"
#include "framework.h"
#include <vector>

std::vector<std::vector<int>> randomState(int , int );
int square(int);
std::vector<std::vector<int>> nextBoardState(std::vector<std::vector<int>>);
void color(int);
void render(std::vector<std::vector<int>>);