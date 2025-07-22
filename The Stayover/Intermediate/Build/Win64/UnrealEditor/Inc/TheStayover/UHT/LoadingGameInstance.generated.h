// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LoadingGameInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UWorld;
#ifdef THESTAYOVER_LoadingGameInstance_generated_h
#error "LoadingGameInstance.generated.h already included, missing '#pragma once' in LoadingGameInstance.h"
#endif
#define THESTAYOVER_LoadingGameInstance_generated_h

#define FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_SPARSE_DATA
#define FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndLoadingScreen); \
	DECLARE_FUNCTION(execBeginLoadingScreen);


#define FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_ACCESSORS
#define FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULoadingGameInstance(); \
	friend struct Z_Construct_UClass_ULoadingGameInstance_Statics; \
public: \
	DECLARE_CLASS(ULoadingGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/TheStayover"), NO_API) \
	DECLARE_SERIALIZER(ULoadingGameInstance)


#define FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULoadingGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULoadingGameInstance(ULoadingGameInstance&&); \
	NO_API ULoadingGameInstance(const ULoadingGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULoadingGameInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULoadingGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULoadingGameInstance) \
	NO_API virtual ~ULoadingGameInstance();


#define FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_8_PROLOG
#define FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_SPARSE_DATA \
	FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_ACCESSORS \
	FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_INCLASS_NO_PURE_DECLS \
	FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> THESTAYOVER_API UClass* StaticClass<class ULoadingGameInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_The_Stayover_Source_TheStayover_LoadingGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
