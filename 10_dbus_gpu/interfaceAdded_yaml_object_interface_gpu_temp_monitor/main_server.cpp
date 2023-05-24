#include <boost/asio.hpp>
#include <xyz/openbmc_project/gpu_temp_monitor/server.hpp>
#include <phosphor-logging/lg2.hpp>
#include <sdbusplus/asio/connection.hpp>
#include <sdbusplus/asio/object_server.hpp>
#include <sdbusplus/asio/property.hpp>
#include <sdbusplus/bus/match.hpp>

#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;

namespace xyz::openbmc_project::gpu_temp_monitor
{
using TestInherit =
    sdbusplus::server::object::object<sdbusplus::xyz::openbmc_project::server::gpu_temp_monitor>;

class Test : public TestInherit
{
  public:
    Test(sdbusplus::bus_t& bus, const char* path) : TestInherit(bus, path)
    {
        std::cout << "GPU::Test()" << std::endl;
	char data[12];
        string str;

	ifstream infile;
	infile.open("/home/root/GPU_TEMP_MONITOR/gpu1_temp");
	infile.getline(data,10);
	str = data;
	GpuTemp0(str);
	infile.close();
	memset(data,0,sizeof(data));
	str.clear();

        infile.open("/home/root/GPU_TEMP_MONITOR/gpu2_temp");
        infile.getline(data,10);
        str = data;
        GpuTemp1(str);
        infile.close();
        memset(data,0,sizeof(data));
        str.clear();

        infile.open("/home/root/GPU_TEMP_MONITOR/gpu3_temp");
        infile.getline(data,10);
        str = data;
        GpuTemp2(str);
        infile.close();
        memset(data,0,sizeof(data));
        str.clear();

        infile.open("/home/root/GPU_TEMP_MONITOR/gpu4_temp");
        infile.getline(data,10);
        str = data;
        GpuTemp3(str);
        infile.close();
        memset(data,0,sizeof(data));
        str.clear();
    }
    ~Test()
    {
        std::cout << "Test::~Test()" << std::endl;
    }
};

} // namespace xyz::openbmc_project::gpu_temp_monitor

int main(int, char const**)
{
    boost::asio::io_context io;
    auto bus = std::make_shared<sdbusplus::asio::connection>(io);

    // If you want emit a interfaces added/removed signal, add this before
    // create object
    sdbusplus::server::manager_t objManager(*bus,
                                            "/xyz/openbmc_project/my_gpu_interface");
    xyz::openbmc_project::gpu_temp_monitor::Test test1(
		*bus, "/xyz/openbmc_project/my_gpu_interface/gpu_temp_monitor");
        
    bus->request_name("xyz.openbmc_project.gpu_temp_monitor_service");
    io.run();
    return 0;
}
