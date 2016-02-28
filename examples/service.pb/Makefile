
default:
	../../bin/protoc3  --cpp_out=. echo.proto
	../../bin/protoc3  --protorpc_out=. --plugin=protoc-gen-protorpc=../../bin/protoc-gen-protorpc echo.proto
