
#include "measuretool.h"

using namespace measure;
using namespace std;
using namespace std::chrono;

MeasureTool::MeasureTool()
{

}

void MeasureTool::measureTime(high_resolution_clock::time_point tIni,
                 std::stringstream& steps)
{
    high_resolution_clock::time_point tEnd = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>( tEnd - tIni ).count();
    steps << "\t:: Duration Time: " << duration << " microseconds. ::" << endl;
}
