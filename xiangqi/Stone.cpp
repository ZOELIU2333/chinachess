﻿#include "Stone.h"


void Stone::rotate()
{
     this->_col = 8-this->_col;
     this->_row = 9-this->_row;
}

