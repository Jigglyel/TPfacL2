# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/racroix/Documents/TPfacL2/Projet survie/_deps/sfml-src"
  "/home/racroix/Documents/TPfacL2/Projet survie/_deps/sfml-build"
  "/home/racroix/Documents/TPfacL2/Projet survie/_deps/sfml-subbuild/sfml-populate-prefix"
  "/home/racroix/Documents/TPfacL2/Projet survie/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/home/racroix/Documents/TPfacL2/Projet survie/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/home/racroix/Documents/TPfacL2/Projet survie/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/home/racroix/Documents/TPfacL2/Projet survie/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/racroix/Documents/TPfacL2/Projet survie/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/racroix/Documents/TPfacL2/Projet survie/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
