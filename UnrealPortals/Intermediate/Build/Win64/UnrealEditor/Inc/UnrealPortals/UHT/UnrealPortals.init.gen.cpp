// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealPortals_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UnrealPortals;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UnrealPortals()
	{
		if (!Z_Registration_Info_UPackage__Script_UnrealPortals.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UnrealPortals",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x2FEC1AC3,
				0x68D9ACCF,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UnrealPortals.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UnrealPortals.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UnrealPortals(Z_Construct_UPackage__Script_UnrealPortals, TEXT("/Script/UnrealPortals"), Z_Registration_Info_UPackage__Script_UnrealPortals, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x2FEC1AC3, 0x68D9ACCF));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
