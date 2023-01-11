.PHONY = debug release clean clean-all

debug:
	cmake -Bbuild/$@ -DCMAKE_BUILD_TYPE=Debug
	cmake --build build/$@ -j $$(nproc)

release:
	cmake -Bbuild/$@ -DCMAKE_BUILD_TYPE=RelWithDebInfo
	cmake --build build/$@ -j $$(nproc)

clean:
	test ! -d build/debug || cmake --build build/debug --target clean
	test ! -d build/release || cmake --build build/release --target clean

clean-all:
	rm build -rf
