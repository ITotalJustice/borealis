cmake_minimum_required(VERSION 3.20.0)

add_library(borealis
    lib/core/logger.cpp
    lib/core/input.cpp
    lib/core/application.cpp
    lib/core/i18n.cpp
    lib/core/theme.cpp
    lib/core/style.cpp
    lib/core/activity.cpp
    lib/core/platform.cpp
    lib/core/geometry.cpp
    lib/core/font.cpp
    lib/core/util.cpp
    lib/core/time.cpp
    lib/core/timer.cpp
    lib/core/animation.cpp
    lib/core/task.cpp
    lib/core/view.cpp
    lib/core/box.cpp
    lib/core/bind.cpp
    lib/core/thread.cpp
    lib/core/gesture.cpp

    lib/core/touch/tap_gesture.cpp
    lib/core/touch/pan_gesture.cpp
    lib/core/touch/scroll_gesture.cpp

    lib/views/scrolling_frame.cpp
    lib/views/applet_frame.cpp
    lib/views/tab_frame.cpp
    lib/views/rectangle.cpp
    lib/views/recycler.cpp
    lib/views/sidebar.cpp
    lib/views/label.cpp
    lib/views/button.cpp
    lib/views/image.cpp
    lib/views/header.cpp
    lib/views/hint.cpp
    lib/views/slider.cpp
    lib/views/dropdown.cpp
    lib/views/progress_spinner.cpp
    lib/views/debug_layer.cpp
    lib/views/bottom_bar.cpp
    lib/views/dialog.cpp
    lib/views/h_scrolling_frame.cpp

    lib/views/cells/cell_bool.cpp
    lib/views/cells/cell_detail.cpp
    lib/views/cells/cell_input.cpp
    lib/views/cells/cell_radio.cpp
    lib/views/cells/cell_selector.cpp

    lib/views/widgets/battery.cpp
    lib/views/widgets/wireless.cpp
    lib/views/widgets/account.cpp

    lib/extern/tinyxml2/tinyxml2.cpp
    lib/extern/fmt/src/format.cc
    lib/extern/fmt/src/os.cc
    lib/extern/libretro-common/compat/compat_strl.c
    lib/extern/libretro-common/features/features_cpu.c
    lib/extern/libretro-common/encodings/encoding_utf.c
    lib/extern/yoga/src/yoga/event/event.cpp
    lib/extern/yoga/src/yoga/log.cpp
    lib/extern/yoga/src/yoga/Utils.cpp
    lib/extern/yoga/src/yoga/YGConfig.cpp
    lib/extern/yoga/src/yoga/YGEnums.cpp
    lib/extern/yoga/src/yoga/YGLayout.cpp
    lib/extern/yoga/src/yoga/YGNode.cpp
    lib/extern/yoga/src/yoga/YGStyle.cpp
    lib/extern/yoga/src/yoga/YGValue.cpp
    lib/extern/yoga/src/yoga/Yoga.cpp
)

target_include_directories(borealis
    PUBLIC
        "include"
        "lib/extern/fmt/include"
        "include/borealis/extern"
        "include/borealis/extern/tinyxml2"
        "lib/extern/yoga/src"
        "lib/extern/tweeny/include"
    PRIVATE
)

if (NINTENDO_SWITCH)
    target_link_libraries(borealis PRIVATE deko3d)

    target_sources(borealis
        PRIVATE
            lib/platforms/switch/switch_audio.cpp
            lib/platforms/switch/switch_font.cpp
            lib/platforms/switch/switch_input.cpp
            lib/platforms/switch/switch_platform.cpp
            lib/platforms/switch/switch_video.cpp
            lib/platforms/switch/swkbd.cpp

            lib/extern/nanovg-deko3d/source/nanovg.c
            lib/extern/nanovg-deko3d/source/dk_renderer.cpp
            lib/extern/nanovg-deko3d/source/framework/CApplication.cpp
            lib/extern/nanovg-deko3d/source/framework/CExternalImage.cpp
            lib/extern/nanovg-deko3d/source/framework/CIntrusiveTree.cpp
            lib/extern/nanovg-deko3d/source/framework/CMemPool.cpp
            lib/extern/nanovg-deko3d/source/framework/CShader.cpp
            lib/extern/nanovg-deko3d/source/framework/FileLoader.cpp

            lib/extern/switch-libpulsar/src/archive/archive_file.c
            lib/extern/switch-libpulsar/src/archive/archive.c

            lib/extern/switch-libpulsar/src/bfgrp/bfgrp_location.c
            lib/extern/switch-libpulsar/src/bfgrp/bfgrp.c

            lib/extern/switch-libpulsar/src/bfsar/bfsar_file.c
            lib/extern/switch-libpulsar/src/bfsar/bfsar_group.c
            lib/extern/switch-libpulsar/src/bfsar/bfsar_sound.c
            lib/extern/switch-libpulsar/src/bfsar/bfsar_string.c
            lib/extern/switch-libpulsar/src/bfsar/bfsar_wave_archive.c
            lib/extern/switch-libpulsar/src/bfsar/bfsar.c

            lib/extern/switch-libpulsar/src/bfwar/bfwar_file.c
            lib/extern/switch-libpulsar/src/bfwar/bfwar.c

            lib/extern/switch-libpulsar/src/bfwav/bfwav_info.c
            lib/extern/switch-libpulsar/src/bfwav/bfwav.c

            lib/extern/switch-libpulsar/src/bfwsd/bfwsd_sound_data.c
            lib/extern/switch-libpulsar/src/bfwsd/bfwsd_wave_id.c
            lib/extern/switch-libpulsar/src/bfwsd/bfwsd.c

            lib/extern/switch-libpulsar/src/player/player_load_lookup.c
            lib/extern/switch-libpulsar/src/player/player_load.c
            lib/extern/switch-libpulsar/src/player/player.c
        PUBLIC
            lib/platforms/switch/switch_wrapper.c
    )

    target_include_directories(borealis
        PUBLIC
            "include"
            "lib/extern/fmt/include"
            "lib/extern/switch-libpulsar/include"
            "lib/extern/nanovg-deko3d/include"
        PRIVATE
            # this is for glm
            ${DEVKITPRO}/portlibs/switch/include
    )

    target_compile_definitions(borealis
        PUBLIC
            YG_ENABLE_EVENTS
            BRLS_RESOURCES="romfs:/"
    )
else()
    find_package(glfw3 3.3 REQUIRED)

    target_link_libraries(borealis PRIVATE glfw)

    target_sources(borealis PRIVATE
        lib/platforms/glfw/glfw_platform.cpp
        lib/platforms/glfw/glfw_video.cpp
        lib/platforms/glfw/glfw_input.cpp
        lib/platforms/glfw/glfw_font.cpp
        lib/platforms/switch/swkbd.cpp

        lib/extern/glad/glad.c
        lib/extern/nanovg-gl/nanovg.c
    )

    target_include_directories(borealis
        PUBLIC
            "include/borealis/extern/nanovg-gl"
        PRIVATE
    )

    target_compile_definitions(borealis
        PUBLIC
            NO_TOUCH_SCROLLING=true
            YG_ENABLE_EVENTS
            __GLFW__
            BRLS_RESOURCES="${CMAKE_SOURCE_DIR}/resources/"
    )
endif()
