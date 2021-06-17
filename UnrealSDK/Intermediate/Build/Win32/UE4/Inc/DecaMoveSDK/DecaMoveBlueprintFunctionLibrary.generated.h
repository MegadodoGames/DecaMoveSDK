// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
enum class EDecaMoveState : uint8;
struct FQuat;
struct FRotator;
#ifdef DECAMOVESDK_DecaMoveBlueprintFunctionLibrary_generated_h
#error "DecaMoveBlueprintFunctionLibrary.generated.h already included, missing '#pragma once' in DecaMoveBlueprintFunctionLibrary.h"
#endif
#define DECAMOVESDK_DecaMoveBlueprintFunctionLibrary_generated_h

#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_SPARSE_DATA
#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetIfDecaMoveTripleClicked); \
	DECLARE_FUNCTION(execGetIfDecaMoveDoubleClicked); \
	DECLARE_FUNCTION(execGetIfDecaMoveSingleClicked); \
	DECLARE_FUNCTION(execSendDecaMoveHaptic); \
	DECLARE_FUNCTION(execCalibrateDecaMove); \
	DECLARE_FUNCTION(execIsDecaMoveSleeping); \
	DECLARE_FUNCTION(execGetDecaMoveState); \
	DECLARE_FUNCTION(execGetDecaMovePostion); \
	DECLARE_FUNCTION(execGetDecaMoveYawOffset); \
	DECLARE_FUNCTION(execGetDecaMoveRawRotation); \
	DECLARE_FUNCTION(execGetDecaMoveRotation);


#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetIfDecaMoveTripleClicked); \
	DECLARE_FUNCTION(execGetIfDecaMoveDoubleClicked); \
	DECLARE_FUNCTION(execGetIfDecaMoveSingleClicked); \
	DECLARE_FUNCTION(execSendDecaMoveHaptic); \
	DECLARE_FUNCTION(execCalibrateDecaMove); \
	DECLARE_FUNCTION(execIsDecaMoveSleeping); \
	DECLARE_FUNCTION(execGetDecaMoveState); \
	DECLARE_FUNCTION(execGetDecaMovePostion); \
	DECLARE_FUNCTION(execGetDecaMoveYawOffset); \
	DECLARE_FUNCTION(execGetDecaMoveRawRotation); \
	DECLARE_FUNCTION(execGetDecaMoveRotation);


#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDecaMoveBlueprintFunctionLibrary(); \
	friend struct Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UDecaMoveBlueprintFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DecaMoveSDK"), NO_API) \
	DECLARE_SERIALIZER(UDecaMoveBlueprintFunctionLibrary)


#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_INCLASS \
private: \
	static void StaticRegisterNativesUDecaMoveBlueprintFunctionLibrary(); \
	friend struct Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UDecaMoveBlueprintFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/DecaMoveSDK"), NO_API) \
	DECLARE_SERIALIZER(UDecaMoveBlueprintFunctionLibrary)


#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDecaMoveBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDecaMoveBlueprintFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDecaMoveBlueprintFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDecaMoveBlueprintFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDecaMoveBlueprintFunctionLibrary(UDecaMoveBlueprintFunctionLibrary&&); \
	NO_API UDecaMoveBlueprintFunctionLibrary(const UDecaMoveBlueprintFunctionLibrary&); \
public:


#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDecaMoveBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDecaMoveBlueprintFunctionLibrary(UDecaMoveBlueprintFunctionLibrary&&); \
	NO_API UDecaMoveBlueprintFunctionLibrary(const UDecaMoveBlueprintFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDecaMoveBlueprintFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDecaMoveBlueprintFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDecaMoveBlueprintFunctionLibrary)


#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_23_PROLOG
#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_SPARSE_DATA \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_RPC_WRAPPERS \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_INCLASS \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_SPARSE_DATA \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> DECAMOVESDK_API UClass* StaticClass<class UDecaMoveBlueprintFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_DecaMoveSDK_Source_DecaMoveSDK_Public_DecaMoveBlueprintFunctionLibrary_h


#define FOREACH_ENUM_EDECAMOVESTATE(op) \
	op(EDecaMoveState::closed) \
	op(EDecaMoveState::open) \
	op(EDecaMoveState::paired) \
	op(EDecaMoveState::streaming) 

enum class EDecaMoveState : uint8;
template<> DECAMOVESDK_API UEnum* StaticEnum<EDecaMoveState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
