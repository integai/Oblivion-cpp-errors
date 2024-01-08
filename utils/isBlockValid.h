#ifndef ISBLOCKVALID_H
#define ISBLOCKVALID_H

#include "../block.h"
#include "../blockchain.h"

bool isBlockValid(const Block& block, const Blockchain& blockchain);

#endif
