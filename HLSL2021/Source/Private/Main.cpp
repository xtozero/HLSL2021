#include "d3d12.h"
#include "dxcapi.h"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <wrl/client.h>

using ::Microsoft::WRL::ComPtr;

void CompileShader( IDxcCompiler3* compiler, const std::filesystem::path& shaderFilePath, std::vector<const wchar_t*> args )
{
	std::ifstream shaderFile;
	shaderFile.open( shaderFilePath, std::ios::binary | std::ios::ate );
	if ( shaderFile.good() == false )
	{
		std::cout << "Failed to open file - " << shaderFilePath << std::endl;
		return;
	}

	std::vector<char> shaderFileBinary;
	size_t fileSize = shaderFile.tellg();
	if ( fileSize == 0 )
	{
		std::cout << "Can't compile empty shader file - " << shaderFilePath << std::endl;
		return;
	}

	shaderFileBinary.resize( shaderFile.tellg() );

	shaderFile.seekg( 0 );
	shaderFile.read( shaderFileBinary.data(), shaderFileBinary.size() );

	DxcBuffer buffer = {
		.Ptr = shaderFileBinary.data(),
		.Size = shaderFileBinary.size(),
		.Encoding = DXC_CP_ACP
	};

	ComPtr<IDxcResult> results;
	compiler->Compile( &buffer
		, args.data()
		, static_cast<UINT32>( args.size() )
		, nullptr
		, IID_PPV_ARGS( results.GetAddressOf() ) );

	HRESULT hr = S_OK;
	results->GetStatus( &hr );

	if ( FAILED( hr ) )
	{
		std::cout << "Failed to compile shader file - " << shaderFilePath << std::endl;
		return;
	}

	ComPtr<IDxcBlob> compiledBinary = nullptr;
	ComPtr<IDxcBlobUtf16> shaderName = nullptr;
	results->GetOutput( DXC_OUT_OBJECT, IID_PPV_ARGS( compiledBinary.GetAddressOf() ), shaderName.GetAddressOf() );

	std::cout << "Shader file compiled successfully - " << shaderFilePath << std::endl;
}

int main( )
{
	ComPtr<IDxcCompiler3> compiler;

	// Create directX shader compiler
	{
		HRESULT hr = DxcCreateInstance( CLSID_DxcCompiler, IID_PPV_ARGS( compiler.GetAddressOf() ) );
		if ( FAILED( hr ) )
		{
			std::cout << "DirectX Shader Compiler creation failed" << std::endl;
			return 1;
		}
	}

	// Setup compile arguments
	std::vector<const wchar_t*> args;

	// Entry point
	args.emplace_back( L"-E" );
	args.emplace_back( L"main" );

	// HLSL version(2016, 2017, 2018, 2021). Default is 2021
	// args.emplace_back( L"-HV" );
	// args.emplace_back( L"2021" );

	// Target profile
	args.emplace_back( L"-T" );
	// Assuming all shader files are compute shaders in this sample
	args.emplace_back( L"cs_6_8" );

	std::filesystem::path shaderFilePaths[] = {
		"Shader/01_strict_casting.hlsl",
		"Shader/02_logical_operator.hlsl",
		"Shader/03_loop_scoping_rules.hlsl",
		"Shader/04_template_function.hlsl",
		"Shader/05_member_operator_overloading.hlsl",
		"Shader/06_bitfield.hlsl",	
	};

	std::cout << "> HLSL 2021" << std::endl;

	// Compile shader
	for ( const auto& shaderFilePath : shaderFilePaths )
	{
		CompileShader( compiler.Get(), shaderFilePath, args );
	}

	std::cout << "> HLSL 2018" << std::endl;

	// HLSL version(2016, 2017, 2018, 2021). Default is 2021
	args.emplace_back( L"-HV" );
	args.emplace_back( L"2018" );

	// Compile shader
	for ( const auto& shaderFilePath : shaderFilePaths )
	{
		CompileShader( compiler.Get(), shaderFilePath, args );
	}

	return 0;
}