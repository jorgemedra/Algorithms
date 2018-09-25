#ifndef MEASURETOOL_H
#define MEASURETOOL_H

#include <tuple>
#include <chrono>
#include<sstream>

namespace measure
{
    class MeasureTool
    {
    public:
        MeasureTool();

        void measureTime(std::chrono::high_resolution_clock::time_point tIni,
                         std::stringstream& steps);
    };
}

#endif // MEASURETOOL_H
