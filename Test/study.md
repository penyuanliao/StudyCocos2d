# cocos2d-x Lua 3.6 Study

###優先加載檔案搜尋路徑
iOS application wirte directory 

```cpp
// set search paths //
std::vector<std::string> paths;
paths.push_back(FileUtils::getInstance()->getWritablePath());
FileUtils::getInstance()->setSearchPaths(paths);
```
```lua
local wPath = cc.FileUtils:getInstance():getWritablePath()
local paths = {wPath}
cc.FileUtils:getInstance():setSearchPaths(paths)
```
###


##使用cocos2d-x的方式來將C++類別註冊到Lua環境
------------------------------------------
###Install Python
###Install Python Pip
// --------------------------
 sudo easy_install pip
 sudo pip install PyYAML
 sudo pip install Cheetah
// --------------------------
*附註1 編譯genbindings_custom.py 是透過NDK裡的llvm-3.3,llvm-3.4但在android-ndk-r10e沒有必須下載android-ndk-r9d
*附註2 ImportError:No module named yaml錯誤則是沒有安裝

###自定義C++類別
 * Path : frameworks/runtime-src/Classes/
 * ini Path : frameworks/cocos2d-x/tools/tolua/
 * hpp Path : frameworks/cocos2d-x/cocos/scripting/lua-bindings/auto

CustomClass.h
```cpp

#include "cocos2d.h"

using namespace cocos2d;

class CustomClass : public Ref
{
public:
	CustomClass() {};
	virtual ~CustomClass() {};
	bool init() { return true; };
	CREATE_FUNC(CustomClass);

	bool HellWorld(const char* name);

};

```
CustomClass.cpp
```cpp

#include "CustomClass.h"

bool CustomClass::HellWorld(const char* name)
{
	printf("HellWorld : %s\n", name);
	
	return true;
}

```
```ini

[CustomClass]
prefix				= CustomClass
target_namespace 	= custom
headers				= %(cocosdir)s/../runtime-src/Classes/CustomClass.h
classes 			= CustomClass

```
[2] 執行genbindings.py 會在 hpp Path產生出lua的cpp, hpp檔案

[3] 出現 < Generating lua bindings succeeds. > 就是成功

[4] cocos2d_lua_bindings.xcodeproj add Project > Build Settings > User Header Search Paths > add CustomClass.h Path
[5] Drag hpp,cpp on xcode "auto" folder.

[6] AppDelegate.app include "lua_CustomClass_auto.hpp"

[7] ScriptEngineManager register register_all_CustomClass(L);