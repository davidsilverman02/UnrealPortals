// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealPortals/UnrealPortalsGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUnrealPortalsGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UNREALPORTALS_API UClass* Z_Construct_UClass_AUnrealPortalsGameMode();
	UNREALPORTALS_API UClass* Z_Construct_UClass_AUnrealPortalsGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealPortals();
// End Cross Module References
	void AUnrealPortalsGameMode::StaticRegisterNativesAUnrealPortalsGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AUnrealPortalsGameMode);
	UClass* Z_Construct_UClass_AUnrealPortalsGameMode_NoRegister()
	{
		return AUnrealPortalsGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AUnrealPortalsGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AUnrealPortalsGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealPortals,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealPortalsGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AUnrealPortalsGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "UnrealPortalsGameMode.h" },
		{ "ModuleRelativePath", "UnrealPortalsGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AUnrealPortalsGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AUnrealPortalsGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AUnrealPortalsGameMode_Statics::ClassParams = {
		&AUnrealPortalsGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AUnrealPortalsGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AUnrealPortalsGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AUnrealPortalsGameMode()
	{
		if (!Z_Registration_Info_UClass_AUnrealPortalsGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AUnrealPortalsGameMode.OuterSingleton, Z_Construct_UClass_AUnrealPortalsGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AUnrealPortalsGameMode.OuterSingleton;
	}
	template<> UNREALPORTALS_API UClass* StaticClass<AUnrealPortalsGameMode>()
	{
		return AUnrealPortalsGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AUnrealPortalsGameMode);
	AUnrealPortalsGameMode::~AUnrealPortalsGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_UnrealPortalsGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_UnrealPortalsGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AUnrealPortalsGameMode, AUnrealPortalsGameMode::StaticClass, TEXT("AUnrealPortalsGameMode"), &Z_Registration_Info_UClass_AUnrealPortalsGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AUnrealPortalsGameMode), 1264870292U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_UnrealPortalsGameMode_h_1778875906(TEXT("/Script/UnrealPortals"),
		Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_UnrealPortalsGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_UnrealPortalsGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
