// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealPortals/PortalObjectComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePortalObjectComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector3f();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UNREALPORTALS_API UClass* Z_Construct_UClass_UPortalObjectComponent();
	UNREALPORTALS_API UClass* Z_Construct_UClass_UPortalObjectComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealPortals();
// End Cross Module References
	struct PortalObjectComponent_eventOnTeleport_Parms
	{
		FTransform fromPortal;
		FTransform toPortal;
		FVector3f pos;
		FRotator rot;
	};
	static FName NAME_UPortalObjectComponent_OnPortalEnterStart = FName(TEXT("OnPortalEnterStart"));
	void UPortalObjectComponent::OnPortalEnterStart()
	{
		ProcessEvent(FindFunctionChecked(NAME_UPortalObjectComponent_OnPortalEnterStart),NULL);
	}
	static FName NAME_UPortalObjectComponent_OnPortalExitStart = FName(TEXT("OnPortalExitStart"));
	void UPortalObjectComponent::OnPortalExitStart()
	{
		ProcessEvent(FindFunctionChecked(NAME_UPortalObjectComponent_OnPortalExitStart),NULL);
	}
	static FName NAME_UPortalObjectComponent_OnTeleport = FName(TEXT("OnTeleport"));
	void UPortalObjectComponent::OnTeleport(FTransform fromPortal, FTransform toPortal, FVector3f pos, FRotator rot)
	{
		PortalObjectComponent_eventOnTeleport_Parms Parms;
		Parms.fromPortal=fromPortal;
		Parms.toPortal=toPortal;
		Parms.pos=pos;
		Parms.rot=rot;
		ProcessEvent(FindFunctionChecked(NAME_UPortalObjectComponent_OnTeleport),&Parms);
	}
	void UPortalObjectComponent::StaticRegisterNativesUPortalObjectComponent()
	{
	}
	struct Z_Construct_UFunction_UPortalObjectComponent_OnPortalEnterStart_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPortalObjectComponent_OnPortalEnterStart_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "OnPortalEnterStart" },
		{ "ModuleRelativePath", "PortalObjectComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPortalObjectComponent_OnPortalEnterStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPortalObjectComponent, nullptr, "OnPortalEnterStart", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPortalObjectComponent_OnPortalEnterStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPortalObjectComponent_OnPortalEnterStart_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPortalObjectComponent_OnPortalEnterStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPortalObjectComponent_OnPortalEnterStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPortalObjectComponent_OnPortalExitStart_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPortalObjectComponent_OnPortalExitStart_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "OnPortalExitStart" },
		{ "ModuleRelativePath", "PortalObjectComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPortalObjectComponent_OnPortalExitStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPortalObjectComponent, nullptr, "OnPortalExitStart", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPortalObjectComponent_OnPortalExitStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPortalObjectComponent_OnPortalExitStart_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UPortalObjectComponent_OnPortalExitStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPortalObjectComponent_OnPortalExitStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_fromPortal;
		static const UECodeGen_Private::FStructPropertyParams NewProp_toPortal;
		static const UECodeGen_Private::FStructPropertyParams NewProp_pos;
		static const UECodeGen_Private::FStructPropertyParams NewProp_rot;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::NewProp_fromPortal = { "fromPortal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PortalObjectComponent_eventOnTeleport_Parms, fromPortal), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::NewProp_toPortal = { "toPortal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PortalObjectComponent_eventOnTeleport_Parms, toPortal), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::NewProp_pos = { "pos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PortalObjectComponent_eventOnTeleport_Parms, pos), Z_Construct_UScriptStruct_FVector3f, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::NewProp_rot = { "rot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PortalObjectComponent_eventOnTeleport_Parms, rot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::NewProp_fromPortal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::NewProp_toPortal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::NewProp_pos,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::NewProp_rot,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "OnTeleport" },
		{ "ModuleRelativePath", "PortalObjectComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPortalObjectComponent, nullptr, "OnTeleport", nullptr, nullptr, Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::PropPointers), sizeof(PortalObjectComponent_eventOnTeleport_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::PropPointers) < 2048);
	static_assert(sizeof(PortalObjectComponent_eventOnTeleport_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPortalObjectComponent_OnTeleport()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPortalObjectComponent_OnTeleport_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPortalObjectComponent);
	UClass* Z_Construct_UClass_UPortalObjectComponent_NoRegister()
	{
		return UPortalObjectComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPortalObjectComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPortalObjectComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealPortals,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPortalObjectComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPortalObjectComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPortalObjectComponent_OnPortalEnterStart, "OnPortalEnterStart" }, // 3999807034
		{ &Z_Construct_UFunction_UPortalObjectComponent_OnPortalExitStart, "OnPortalExitStart" }, // 1262398853
		{ &Z_Construct_UFunction_UPortalObjectComponent_OnTeleport, "OnTeleport" }, // 1570243049
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPortalObjectComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPortalObjectComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//struct FTransform;\n" },
#endif
		{ "IncludePath", "PortalObjectComponent.h" },
		{ "ModuleRelativePath", "PortalObjectComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "struct FTransform;" },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPortalObjectComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPortalObjectComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPortalObjectComponent_Statics::ClassParams = {
		&UPortalObjectComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPortalObjectComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPortalObjectComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UPortalObjectComponent()
	{
		if (!Z_Registration_Info_UClass_UPortalObjectComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPortalObjectComponent.OuterSingleton, Z_Construct_UClass_UPortalObjectComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPortalObjectComponent.OuterSingleton;
	}
	template<> UNREALPORTALS_API UClass* StaticClass<UPortalObjectComponent>()
	{
		return UPortalObjectComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPortalObjectComponent);
	UPortalObjectComponent::~UPortalObjectComponent() {}
	struct Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_PortalObjectComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_PortalObjectComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPortalObjectComponent, UPortalObjectComponent::StaticClass, TEXT("UPortalObjectComponent"), &Z_Registration_Info_UClass_UPortalObjectComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPortalObjectComponent), 763235027U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_PortalObjectComponent_h_4268319900(TEXT("/Script/UnrealPortals"),
		Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_PortalObjectComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_PortalObjectComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
