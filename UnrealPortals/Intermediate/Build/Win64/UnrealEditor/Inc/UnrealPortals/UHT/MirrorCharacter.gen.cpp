// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealPortals/MirrorCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMirrorCharacter() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
	UNREALPORTALS_API UClass* Z_Construct_UClass_AMirrorCharacter();
	UNREALPORTALS_API UClass* Z_Construct_UClass_AMirrorCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealPortals();
// End Cross Module References
	void AMirrorCharacter::StaticRegisterNativesAMirrorCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMirrorCharacter);
	UClass* Z_Construct_UClass_AMirrorCharacter_NoRegister()
	{
		return AMirrorCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AMirrorCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_original_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_original;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMirrorCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealPortals,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMirrorCharacter_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMirrorCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MirrorCharacter.h" },
		{ "ModuleRelativePath", "MirrorCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMirrorCharacter_Statics::NewProp_original_MetaData[] = {
		{ "Category", "MirrorCharacter" },
		{ "ModuleRelativePath", "MirrorCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMirrorCharacter_Statics::NewProp_original = { "original", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMirrorCharacter, original), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMirrorCharacter_Statics::NewProp_original_MetaData), Z_Construct_UClass_AMirrorCharacter_Statics::NewProp_original_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMirrorCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMirrorCharacter_Statics::NewProp_original,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMirrorCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMirrorCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMirrorCharacter_Statics::ClassParams = {
		&AMirrorCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMirrorCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMirrorCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMirrorCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AMirrorCharacter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMirrorCharacter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AMirrorCharacter()
	{
		if (!Z_Registration_Info_UClass_AMirrorCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMirrorCharacter.OuterSingleton, Z_Construct_UClass_AMirrorCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMirrorCharacter.OuterSingleton;
	}
	template<> UNREALPORTALS_API UClass* StaticClass<AMirrorCharacter>()
	{
		return AMirrorCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMirrorCharacter);
	AMirrorCharacter::~AMirrorCharacter() {}
	struct Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_MirrorCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_MirrorCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMirrorCharacter, AMirrorCharacter::StaticClass, TEXT("AMirrorCharacter"), &Z_Registration_Info_UClass_AMirrorCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMirrorCharacter), 2693760135U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_MirrorCharacter_h_3059653245(TEXT("/Script/UnrealPortals"),
		Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_MirrorCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_MirrorCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
