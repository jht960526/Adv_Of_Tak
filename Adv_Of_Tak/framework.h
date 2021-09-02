#pragma once

// 라이브러리를 인클루드 합니다.

// 정규라이브러리를 포함합니다. EX) <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#define DELETE(x) if(x) delete (x); (x) = nullptr
using namespace sf;

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <random>
#include <typeinfo>
#include <string.h>
using namespace std;