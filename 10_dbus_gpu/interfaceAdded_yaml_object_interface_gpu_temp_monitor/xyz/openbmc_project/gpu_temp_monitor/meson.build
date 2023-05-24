gpu_temp_monitor_hpp = custom_target(
    'server.hpp',
    capture: true,
    command: [
        sdbuspp,
        '-r', meson.source_root() / '10_dbus_gpu/interfaceAdded_yaml_object_interface_gpu_temp_monitor',
        'interface',
        'server-header',
        'xyz.openbmc_project.gpu_temp',
    ],
    input: '../gpu_temp_monitor.interface.yaml',
    install: true,
    install_dir: get_option('includedir') / 'xyz/openbmc_project/gpu_temp_monitor',
    output: 'server.hpp',
)

gpu_temp_monitor_cpp = custom_target(
    'server.cpp',
    capture: true,
    command: [
        sdbuspp,
        '-r', meson.source_root() / '10_dbus_gpu/interfaceAdded_yaml_object_interface_gpu_temp_monitor',
        'interface',
        'server-cpp',
        'xyz.openbmc_project.gpu_temp',
    ],
    input: '../gpu_temp_monitor.interface.yaml',
    output: 'server.cpp',
)
