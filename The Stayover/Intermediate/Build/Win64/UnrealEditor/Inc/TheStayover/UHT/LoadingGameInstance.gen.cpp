// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TheStayover/LoadingGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLoadingGameInstance() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	THESTAYOVER_API UClass* Z_Construct_UClass_ULoadingGameInstance();
	THESTAYOVER_API UClass* Z_Construct_UClass_ULoadingGameInstance_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TheStayover();
// End Cross Module References
	DEFINE_FUNCTION(ULoadingGameInstance::execEndLoadingScreen)
	{
		P_GET_OBJECT(UWorld,Z_Param_InLoadedWorld);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndLoadingScreen(Z_Param_InLoadedWorld);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ULoadingGameInstance::execBeginLoadingScreen)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_MapName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginLoadingScreen(Z_Param_MapName);
		P_NATIVE_END;
	}
	void ULoadingGameInstance::StaticRegisterNativesULoadingGameInstance()
	{
		UClass* Class = ULoadingGameInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BeginLoadingScreen", &ULoadingGameInstance::execBeginLoadingScreen },
			{ "EndLoadingScreen", &ULoadingGameInstance::execEndLoadingScreen },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics
	{
		struct LoadingGameInstance_eventBeginLoadingScreen_Parms
		{
			FString MapName;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MapName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_MapName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::NewProp_MapName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::NewProp_MapName = { "MapName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoadingGameInstance_eventBeginLoadingScreen_Parms, MapName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::NewProp_MapName_MetaData), Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::NewProp_MapName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::NewProp_MapName,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "LoadingGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadingGameInstance, nullptr, "BeginLoadingScreen", nullptr, nullptr, Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::LoadingGameInstance_eventBeginLoadingScreen_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::LoadingGameInstance_eventBeginLoadingScreen_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics
	{
		struct LoadingGameInstance_eventEndLoadingScreen_Parms
		{
			UWorld* InLoadedWorld;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InLoadedWorld;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::NewProp_InLoadedWorld = { "InLoadedWorld", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(LoadingGameInstance_eventEndLoadingScreen_Parms, InLoadedWorld), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::NewProp_InLoadedWorld,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "LoadingGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ULoadingGameInstance, nullptr, "EndLoadingScreen", nullptr, nullptr, Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::PropPointers), sizeof(Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::LoadingGameInstance_eventEndLoadingScreen_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::Function_MetaDataParams), Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::LoadingGameInstance_eventEndLoadingScreen_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULoadingGameInstance);
	UClass* Z_Construct_UClass_ULoadingGameInstance_NoRegister()
	{
		return ULoadingGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_ULoadingGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoadingScreenWidget_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_LoadingScreenWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULoadingGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_TheStayover,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULoadingGameInstance_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ULoadingGameInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ULoadingGameInstance_BeginLoadingScreen, "BeginLoadingScreen" }, // 1503573210
		{ &Z_Construct_UFunction_ULoadingGameInstance_EndLoadingScreen, "EndLoadingScreen" }, // 1137731200
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULoadingGameInstance_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoadingGameInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LoadingGameInstance.h" },
		{ "ModuleRelativePath", "LoadingGameInstance.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULoadingGameInstance_Statics::NewProp_LoadingScreenWidget_MetaData[] = {
		{ "Category", "Loading Screen" },
		{ "ModuleRelativePath", "LoadingGameInstance.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ULoadingGameInstance_Statics::NewProp_LoadingScreenWidget = { "LoadingScreenWidget", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ULoadingGameInstance, LoadingScreenWidget), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULoadingGameInstance_Statics::NewProp_LoadingScreenWidget_MetaData), Z_Construct_UClass_ULoadingGameInstance_Statics::NewProp_LoadingScreenWidget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULoadingGameInstance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULoadingGameInstance_Statics::NewProp_LoadingScreenWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULoadingGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULoadingGameInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULoadingGameInstance_Statics::ClassParams = {
		&ULoadingGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ULoadingGameInstance_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ULoadingGameInstance_Statics::PropPointers),
		0,
		0x009000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULoadingGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_ULoadingGameInstance_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULoadingGameInstance_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ULoadingGameInstance()
	{
		if (!Z_Registration_Info_UClass_ULoadingGameInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULoadingGameInstance.OuterSingleton, Z_Construct_UClass_ULoadingGameInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULoadingGameInstance.OuterSingleton;
	}
	template<> THESTAYOVER_API UClass* StaticClass<ULoadingGameInstance>()
	{
		return ULoadingGameInstance::StaticClass();
	}
	ULoadingGameInstance::ULoadingGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULoadingGameInstance);
	ULoadingGameInstance::~ULoadingGameInstance() {}
	struct Z_CompiledInDeferFile_FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULoadingGameInstance, ULoadingGameInstance::StaticClass, TEXT("ULoadingGameInstance"), &Z_Registration_Info_UClass_ULoadingGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULoadingGameInstance), 549753794U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_49567026(TEXT("/Script/TheStayover"),
		Z_CompiledInDeferFile_FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
