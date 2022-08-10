cmake_minimum_required(VERSION 3.20.0)

add_executable(borealise_demo
    main.cpp
    main_activity.cpp
    captioned_image.cpp
    recycling_list_tab.cpp
    components_tab.cpp
    pokemon_view.cpp
    settings_tab.cpp
)

target_link_libraries(borealise_demo PRIVATE borealis)

dkp_add_asset_target(main_romfs ${CMAKE_SOURCE_DIR}/resources)

nx_generate_nacp(borealise_demo.nacp
    NAME "borealise_demo"
    AUTHOR natinusala
    VERSION 1.0
)

nx_create_nro(borealise_demo
    ICON ${CMAKE_SOURCE_DIR}/resources/img/demo_icon.jpg
    NACP borealise_demo.nacp
    ROMFS main_romfs
)

set(SHADER_FOLDER ${CMAKE_SOURCE_DIR}/library/lib/extern/nanovg-deko3d/shaders/)

nx_add_shader_program(fill_fsh
    ${SHADER_FOLDER}/fill_fsh.glsl
    frag
)

nx_add_shader_program(fill_aa_fsh
    ${SHADER_FOLDER}/fill_aa_fsh.glsl
    frag
)

nx_add_shader_program(fill_vsh
    ${SHADER_FOLDER}/fill_vsh.glsl
    vert
)

dkp_install_assets(main_romfs
    DESTINATION shaders
    TARGETS
        fill_fsh
        fill_aa_fsh
        fill_vsh
)
