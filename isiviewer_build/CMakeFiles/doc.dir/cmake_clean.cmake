FILE(REMOVE_RECURSE
  "CMakeFiles/doc"
  "html/index.html"
  "ui_my_gui_form.h"
  "moc_my_main_window.cxx"
  "moc_my_scene.cxx"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/doc.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
