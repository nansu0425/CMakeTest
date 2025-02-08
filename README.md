# Overview

Visual Studio 2022에서 크로스플랫폼 C++ 앱을 빌드하고 디버깅할 수 있는 CMake 프로젝트 구성 예제입니다. 원격 리눅스(Ubuntu 24.04)에 연결하여 로컬 윈도우(Windows 11)에서 개발하는 환경을 기준으로 구성했습니다. 빌드 configuration 구성을 수정하고 싶다면 CMakePresets.json를 수정하면 됩니다. vcpkg를 이용해 의존성 관리를 합니다. CMake 실행 시 vcpkg.json에 명시된 의존성 패키지를 자동으로 설치합니다. 빌드된 프로그램은 Asio 라이브러리를 이용해 비동기로 Hello, World!를 출력합니다.

# Prerequisites

아래 링크를 참고하여 프로젝트에 필요한 도구 설치와 설정을 진행하세요.

- [CMake projects in Visual Studio](https://learn.microsoft.com/ko-kr/cpp/build/cmake-projects-in-visual-studio?view=msvc-170)
- [Tutorial: Create C++ cross-platform projects in Visual Studio](https://learn.microsoft.com/ko-kr/cpp/build/get-started-linux-cmake?view=msvc-170)

# Demo

- [Visual Studio | 크로스플랫폼 CMake 프로젝트 예제](https://www.youtube.com/watch?v=Yn2SrqHXhnQ)
