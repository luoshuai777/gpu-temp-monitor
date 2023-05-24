# use to create a fanctrl interface
subdir('xyz/openbmc_project/gpu_temp_monitor')

executable(
  'gpu_temp_monitor',
  'main_server.cpp',
  gpu_temp_monitor_cpp,
  gpu_temp_monitor_hpp,
  dependencies: [
    sdbusplus_dep,
    phosphor_logging_dep,
  ],
  implicit_include_directories: true,
  install: true
)

