cmake_minimum_required(VERSION 3.20.0)

add_executable(borealis_demo
    main.cpp
    main_activity.cpp
    captioned_image.cpp
    recycling_list_tab.cpp
    components_tab.cpp
    pokemon_view.cpp
    settings_tab.cpp
)

target_link_libraries(borealis_demo PRIVATE borealis)

if (NINTENDO_SWITCH)
    # only copy needed files as to not bloat romfs
    file(COPY ${CMAKE_SOURCE_DIR}/resources/i18n/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/romfs/i18n/)
    file(COPY ${CMAKE_SOURCE_DIR}/resources/img/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/romfs/img/)
    file(COPY ${CMAKE_SOURCE_DIR}/resources/material/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/romfs/material/)
    file(COPY ${CMAKE_SOURCE_DIR}/resources/xml/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/romfs/xml/)

    dkp_add_asset_target(romfs ${CMAKE_CURRENT_BINARY_DIR}/romfs)

    nx_generate_nacp(borealis_demo.nacp
        NAME "borealis demo"
        AUTHOR natinusala
        VERSION 1.0
    )

    nx_create_nro(borealis_demo
        ICON ${CMAKE_SOURCE_DIR}/resources/img/demo_icon.jpg
        NACP borealis_demo.nacp
        ROMFS romfs
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

    dkp_install_assets(romfs
        DESTINATION shaders
        TARGETS
            fill_fsh
            fill_aa_fsh
            fill_vsh
    )
endif()
