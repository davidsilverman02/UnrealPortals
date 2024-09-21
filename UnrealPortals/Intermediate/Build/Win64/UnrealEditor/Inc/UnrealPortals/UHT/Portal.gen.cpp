// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UnrealPortals/Portal.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePortal() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
	UNREALPORTALS_API UClass* Z_Construct_UClass_APortal();
	UNREALPORTALS_API UClass* Z_Construct_UClass_APortal_NoRegister();
	UPackage* Z_Construct_UPackage__Script_UnrealPortals();
// End Cross Module References
	DEFINE_FUNCTION(APortal::execinitializeMaterials)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->initializeMaterials();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APortal::execsetPortalMaterial)
	{
		P_GET_OBJECT(UMaterial,Z_Param_baseMatter);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->setPortalMaterial(Z_Param_baseMatter);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APortal::execisPointCrossing)
	{
		P_GET_STRUCT(FVector,Z_Param_point);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->isPointCrossing(Z_Param_point);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APortal::execgetViewport)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector2D*)Z_Param__Result=P_THIS->getViewport();
		P_NATIVE_END;
	}
	static FName NAME_APortal_testPortal = FName(TEXT("testPortal"));
	void APortal::testPortal()
	{
		ProcessEvent(FindFunctionChecked(NAME_APortal_testPortal),NULL);
	}
	void APortal::StaticRegisterNativesAPortal()
	{
		UClass* Class = APortal::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "getViewport", &APortal::execgetViewport },
			{ "initializeMaterials", &APortal::execinitializeMaterials },
			{ "isPointCrossing", &APortal::execisPointCrossing },
			{ "setPortalMaterial", &APortal::execsetPortalMaterial },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APortal_getViewport_Statics
	{
		struct Portal_eventgetViewport_Parms
		{
			FVector2D ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APortal_getViewport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Portal_eventgetViewport_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APortal_getViewport_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APortal_getViewport_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APortal_getViewport_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APortal_getViewport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APortal, nullptr, "getViewport", nullptr, nullptr, Z_Construct_UFunction_APortal_getViewport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_getViewport_Statics::PropPointers), sizeof(Z_Construct_UFunction_APortal_getViewport_Statics::Portal_eventgetViewport_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_getViewport_Statics::Function_MetaDataParams), Z_Construct_UFunction_APortal_getViewport_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_getViewport_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APortal_getViewport_Statics::Portal_eventgetViewport_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APortal_getViewport()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APortal_getViewport_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APortal_initializeMaterials_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APortal_initializeMaterials_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APortal_initializeMaterials_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APortal, nullptr, "initializeMaterials", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_initializeMaterials_Statics::Function_MetaDataParams), Z_Construct_UFunction_APortal_initializeMaterials_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_APortal_initializeMaterials()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APortal_initializeMaterials_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APortal_isPointCrossing_Statics
	{
		struct Portal_eventisPointCrossing_Parms
		{
			FVector point;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_point;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APortal_isPointCrossing_Statics::NewProp_point = { "point", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Portal_eventisPointCrossing_Parms, point), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_APortal_isPointCrossing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Portal_eventisPointCrossing_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_APortal_isPointCrossing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Portal_eventisPointCrossing_Parms), &Z_Construct_UFunction_APortal_isPointCrossing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APortal_isPointCrossing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APortal_isPointCrossing_Statics::NewProp_point,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APortal_isPointCrossing_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APortal_isPointCrossing_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APortal_isPointCrossing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APortal, nullptr, "isPointCrossing", nullptr, nullptr, Z_Construct_UFunction_APortal_isPointCrossing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_isPointCrossing_Statics::PropPointers), sizeof(Z_Construct_UFunction_APortal_isPointCrossing_Statics::Portal_eventisPointCrossing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_isPointCrossing_Statics::Function_MetaDataParams), Z_Construct_UFunction_APortal_isPointCrossing_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_isPointCrossing_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APortal_isPointCrossing_Statics::Portal_eventisPointCrossing_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APortal_isPointCrossing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APortal_isPointCrossing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APortal_setPortalMaterial_Statics
	{
		struct Portal_eventsetPortalMaterial_Parms
		{
			UMaterial* baseMatter;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_baseMatter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_APortal_setPortalMaterial_Statics::NewProp_baseMatter = { "baseMatter", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Portal_eventsetPortalMaterial_Parms, baseMatter), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APortal_setPortalMaterial_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APortal_setPortalMaterial_Statics::NewProp_baseMatter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APortal_setPortalMaterial_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Blueprint called functions\n" },
#endif
		{ "ModuleRelativePath", "Portal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint called functions" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APortal_setPortalMaterial_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APortal, nullptr, "setPortalMaterial", nullptr, nullptr, Z_Construct_UFunction_APortal_setPortalMaterial_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_setPortalMaterial_Statics::PropPointers), sizeof(Z_Construct_UFunction_APortal_setPortalMaterial_Statics::Portal_eventsetPortalMaterial_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_setPortalMaterial_Statics::Function_MetaDataParams), Z_Construct_UFunction_APortal_setPortalMaterial_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_setPortalMaterial_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_APortal_setPortalMaterial_Statics::Portal_eventsetPortalMaterial_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_APortal_setPortalMaterial()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APortal_setPortalMaterial_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APortal_testPortal_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APortal_testPortal_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APortal_testPortal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APortal, nullptr, "testPortal", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APortal_testPortal_Statics::Function_MetaDataParams), Z_Construct_UFunction_APortal_testPortal_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_APortal_testPortal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APortal_testPortal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APortal);
	UClass* Z_Construct_UClass_APortal_NoRegister()
	{
		return APortal::StaticClass();
	}
	struct Z_Construct_UClass_APortal_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_defaultComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_defaultComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_portalCollider_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_portalCollider;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_intersectionCollider_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_intersectionCollider;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_portalCam_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_portalCam;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_playCam_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_playCam;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_teleportBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_teleportBox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_playerNearbyBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_playerNearbyBox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ForwardArrow_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ForwardArrow;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_portalBasis_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_portalBasis;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_otherPortal_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_otherPortal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_vision_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_vision;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_maxRecursions_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_maxRecursions;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_portalQuality_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_portalQuality;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_nearClipOffset_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_nearClipOffset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_nearClipLimit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_nearClipLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_portalClipBaseRange_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_portalClipBaseRange;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_portalMatter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_portalMatter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rendTarg_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_rendTarg;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APortal_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UnrealPortals,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_APortal_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APortal_getViewport, "getViewport" }, // 1670365476
		{ &Z_Construct_UFunction_APortal_initializeMaterials, "initializeMaterials" }, // 683769587
		{ &Z_Construct_UFunction_APortal_isPointCrossing, "isPointCrossing" }, // 605872824
		{ &Z_Construct_UFunction_APortal_setPortalMaterial, "setPortalMaterial" }, // 2030455649
		{ &Z_Construct_UFunction_APortal_testPortal, "testPortal" }, // 2137945007
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Portal.h" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_defaultComp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Portal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_defaultComp = { "defaultComp", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, defaultComp), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_defaultComp_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_defaultComp_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_portalCollider_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Portal" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Tinker with to see if editable\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Portal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Tinker with to see if editable" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_portalCollider = { "portalCollider", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, portalCollider), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_portalCollider_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_portalCollider_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_intersectionCollider_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Portal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_intersectionCollider = { "intersectionCollider", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, intersectionCollider), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_intersectionCollider_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_intersectionCollider_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_portalCam_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Portal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_portalCam = { "portalCam", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, portalCam), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_portalCam_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_portalCam_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_playCam_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Portal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_playCam = { "playCam", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, playCam), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_playCam_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_playCam_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_teleportBox_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Portal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_teleportBox = { "teleportBox", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, teleportBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_teleportBox_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_teleportBox_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_playerNearbyBox_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Portal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_playerNearbyBox = { "playerNearbyBox", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, playerNearbyBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_playerNearbyBox_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_playerNearbyBox_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_ForwardArrow_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Portal" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_ForwardArrow = { "ForwardArrow", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, ForwardArrow), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_ForwardArrow_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_ForwardArrow_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_portalBasis_MetaData[] = {
		{ "Category", "PortalData" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_portalBasis = { "portalBasis", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, portalBasis), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_portalBasis_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_portalBasis_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_otherPortal_MetaData[] = {
		{ "Category", "PortalData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The Portal this specific portal goes to\n" },
#endif
		{ "ModuleRelativePath", "Portal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The Portal this specific portal goes to" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_otherPortal = { "otherPortal", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, otherPortal), Z_Construct_UClass_APortal_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_otherPortal_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_otherPortal_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_vision_MetaData[] = {
		{ "Category", "PortalData" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_vision = { "vision", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, vision), Z_Construct_UClass_UMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_vision_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_vision_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_maxRecursions_MetaData[] = {
		{ "Category", "PortalData" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_maxRecursions = { "maxRecursions", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, maxRecursions), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_maxRecursions_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_maxRecursions_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_portalQuality_MetaData[] = {
		{ "Category", "PortalData" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_portalQuality = { "portalQuality", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, portalQuality), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_portalQuality_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_portalQuality_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_nearClipOffset_MetaData[] = {
		{ "Category", "PortalData" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_nearClipOffset = { "nearClipOffset", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, nearClipOffset), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_nearClipOffset_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_nearClipOffset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_nearClipLimit_MetaData[] = {
		{ "Category", "PortalData" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_nearClipLimit = { "nearClipLimit", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, nearClipLimit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_nearClipLimit_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_nearClipLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_portalClipBaseRange_MetaData[] = {
		{ "Category", "PortalData" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_portalClipBaseRange = { "portalClipBaseRange", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, portalClipBaseRange), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_portalClipBaseRange_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_portalClipBaseRange_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_portalMatter_MetaData[] = {
		{ "Category", "PortalData" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_portalMatter = { "portalMatter", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, portalMatter), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_portalMatter_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_portalMatter_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APortal_Statics::NewProp_rendTarg_MetaData[] = {
		{ "Category", "PortalData" },
		{ "ModuleRelativePath", "Portal.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APortal_Statics::NewProp_rendTarg = { "rendTarg", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APortal, rendTarg), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::NewProp_rendTarg_MetaData), Z_Construct_UClass_APortal_Statics::NewProp_rendTarg_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APortal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_defaultComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_portalCollider,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_intersectionCollider,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_portalCam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_playCam,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_teleportBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_playerNearbyBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_ForwardArrow,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_portalBasis,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_otherPortal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_vision,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_maxRecursions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_portalQuality,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_nearClipOffset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_nearClipLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_portalClipBaseRange,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_portalMatter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APortal_Statics::NewProp_rendTarg,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APortal_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APortal>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APortal_Statics::ClassParams = {
		&APortal::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APortal_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::Class_MetaDataParams), Z_Construct_UClass_APortal_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APortal_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_APortal()
	{
		if (!Z_Registration_Info_UClass_APortal.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APortal.OuterSingleton, Z_Construct_UClass_APortal_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APortal.OuterSingleton;
	}
	template<> UNREALPORTALS_API UClass* StaticClass<APortal>()
	{
		return APortal::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APortal);
	APortal::~APortal() {}
	struct Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_Portal_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_Portal_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APortal, APortal::StaticClass, TEXT("APortal"), &Z_Registration_Info_UClass_APortal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APortal), 133928176U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_Portal_h_1860138069(TEXT("/Script/UnrealPortals"),
		Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_Portal_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_david_silverman_source_UnrealPortals_UnrealPortals_Source_UnrealPortals_Portal_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
