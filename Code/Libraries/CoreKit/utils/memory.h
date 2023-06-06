//
// Created by Willow Bracker on 06/06/2023.
//

#pragma once

#define memcpy(source, destination, count) __builtin_memcpy((destination), (source), (count))
