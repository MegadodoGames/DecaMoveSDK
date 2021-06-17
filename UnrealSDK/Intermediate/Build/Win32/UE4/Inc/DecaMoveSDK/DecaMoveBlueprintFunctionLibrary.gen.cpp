// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DecaMoveSDK/Public/DecaMoveBlueprintFunctionLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDecaMoveBlueprintFunctionLibrary() {}
// Cross Module References
	DECAMOVESDK_API UEnum* Z_Construct_UEnum_DecaMoveSDK_EDecaMoveState();
	UPackage* Z_Construct_UPackage__Script_DecaMoveSDK();
	DECAMOVESDK_API UClass* Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_NoRegister();
	DECAMOVESDK_API UClass* Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
// End Cross Module References
	static UEnum* EDecaMoveState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_DecaMoveSDK_EDecaMoveState, Z_Construct_UPackage__Script_DecaMoveSDK(), TEXT("EDecaMoveState"));
		}
		return Singleton;
	}
	template<> DECAMOVESDK_API UEnum* StaticEnum<EDecaMoveState>()
	{
		return EDecaMoveState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EDecaMoveState(EDecaMoveState_StaticEnum, TEXT("/Script/DecaMoveSDK"), TEXT("EDecaMoveState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_DecaMoveSDK_EDecaMoveState_Hash() { return 3723630555U; }
	UEnum* Z_Construct_UEnum_DecaMoveSDK_EDecaMoveState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_DecaMoveSDK();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EDecaMoveState"), 0, Get_Z_Construct_UEnum_DecaMoveSDK_EDecaMoveState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EDecaMoveState::closed", (int64)EDecaMoveState::closed },
				{ "EDecaMoveState::open", (int64)EDecaMoveState::open },
				{ "EDecaMoveState::paired", (int64)EDecaMoveState::paired },
				{ "EDecaMoveState::streaming", (int64)EDecaMoveState::streaming },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "closed.DisplayName", "Closed" },
				{ "closed.Name", "EDecaMoveState::closed" },
				{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
				{ "open.DisplayName", "Open" },
				{ "open.Name", "EDecaMoveState::open" },
				{ "paired.DisplayName", "Paired" },
				{ "paired.Name", "EDecaMoveState::paired" },
				{ "streaming.DisplayName", "Streaming" },
				{ "streaming.Name", "EDecaMoveState::streaming" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_DecaMoveSDK,
				nullptr,
				"EDecaMoveState",
				"EDecaMoveState",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execGetIfDecaMoveTripleClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDecaMoveBlueprintFunctionLibrary::GetIfDecaMoveTripleClicked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execGetIfDecaMoveDoubleClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDecaMoveBlueprintFunctionLibrary::GetIfDecaMoveDoubleClicked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execGetIfDecaMoveSingleClicked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDecaMoveBlueprintFunctionLibrary::GetIfDecaMoveSingleClicked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execSendDecaMoveHaptic)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		UDecaMoveBlueprintFunctionLibrary::SendDecaMoveHaptic();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execCalibrateDecaMove)
	{
		P_GET_STRUCT(FVector,Z_Param_forward);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDecaMoveBlueprintFunctionLibrary::CalibrateDecaMove(Z_Param_forward);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execIsDecaMoveSleeping)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDecaMoveBlueprintFunctionLibrary::IsDecaMoveSleeping();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execGetDecaMoveState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EDecaMoveState*)Z_Param__Result=UDecaMoveBlueprintFunctionLibrary::GetDecaMoveState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execGetDecaMovePostion)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UDecaMoveBlueprintFunctionLibrary::GetDecaMovePostion();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execGetDecaMoveYawOffset)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UDecaMoveBlueprintFunctionLibrary::GetDecaMoveYawOffset();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execGetDecaMoveRawRotation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FQuat*)Z_Param__Result=UDecaMoveBlueprintFunctionLibrary::GetDecaMoveRawRotation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDecaMoveBlueprintFunctionLibrary::execGetDecaMoveRotation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FRotator*)Z_Param__Result=UDecaMoveBlueprintFunctionLibrary::GetDecaMoveRotation();
		P_NATIVE_END;
	}
	void UDecaMoveBlueprintFunctionLibrary::StaticRegisterNativesUDecaMoveBlueprintFunctionLibrary()
	{
		UClass* Class = UDecaMoveBlueprintFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CalibrateDecaMove", &UDecaMoveBlueprintFunctionLibrary::execCalibrateDecaMove },
			{ "GetDecaMovePostion", &UDecaMoveBlueprintFunctionLibrary::execGetDecaMovePostion },
			{ "GetDecaMoveRawRotation", &UDecaMoveBlueprintFunctionLibrary::execGetDecaMoveRawRotation },
			{ "GetDecaMoveRotation", &UDecaMoveBlueprintFunctionLibrary::execGetDecaMoveRotation },
			{ "GetDecaMoveState", &UDecaMoveBlueprintFunctionLibrary::execGetDecaMoveState },
			{ "GetDecaMoveYawOffset", &UDecaMoveBlueprintFunctionLibrary::execGetDecaMoveYawOffset },
			{ "GetIfDecaMoveDoubleClicked", &UDecaMoveBlueprintFunctionLibrary::execGetIfDecaMoveDoubleClicked },
			{ "GetIfDecaMoveSingleClicked", &UDecaMoveBlueprintFunctionLibrary::execGetIfDecaMoveSingleClicked },
			{ "GetIfDecaMoveTripleClicked", &UDecaMoveBlueprintFunctionLibrary::execGetIfDecaMoveTripleClicked },
			{ "IsDecaMoveSleeping", &UDecaMoveBlueprintFunctionLibrary::execIsDecaMoveSleeping },
			{ "SendDecaMoveHaptic", &UDecaMoveBlueprintFunctionLibrary::execSendDecaMoveHaptic },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventCalibrateDecaMove_Parms
		{
			FVector forward;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_forward;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::NewProp_forward = { "forward", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DecaMoveBlueprintFunctionLibrary_eventCalibrateDecaMove_Parms, forward), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::NewProp_forward,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "CalibrateDecaMove", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventCalibrateDecaMove_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventGetDecaMovePostion_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DecaMoveBlueprintFunctionLibrary_eventGetDecaMovePostion_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "GetDecaMovePostion", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventGetDecaMovePostion_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveRawRotation_Parms
		{
			FQuat ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveRawRotation_Parms, ReturnValue), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "GetDecaMoveRawRotation", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveRawRotation_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveRotation_Parms
		{
			FRotator ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveRotation_Parms, ReturnValue), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "GetDecaMoveRotation", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveRotation_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveState_Parms
		{
			EDecaMoveState ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveState_Parms, ReturnValue), Z_Construct_UEnum_DecaMoveSDK_EDecaMoveState, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::NewProp_ReturnValue_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "GetDecaMoveState", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveState_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveYawOffset_Parms
		{
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveYawOffset_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "GetDecaMoveYawOffset", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventGetDecaMoveYawOffset_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveDoubleClicked_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveDoubleClicked_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveDoubleClicked_Parms), &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "GetIfDecaMoveDoubleClicked", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveDoubleClicked_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveSingleClicked_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveSingleClicked_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveSingleClicked_Parms), &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "GetIfDecaMoveSingleClicked", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveSingleClicked_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveTripleClicked_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveTripleClicked_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveTripleClicked_Parms), &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "GetIfDecaMoveTripleClicked", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventGetIfDecaMoveTripleClicked_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics
	{
		struct DecaMoveBlueprintFunctionLibrary_eventIsDecaMoveSleeping_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((DecaMoveBlueprintFunctionLibrary_eventIsDecaMoveSleeping_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(DecaMoveBlueprintFunctionLibrary_eventIsDecaMoveSleeping_Parms), &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "IsDecaMoveSleeping", nullptr, nullptr, sizeof(DecaMoveBlueprintFunctionLibrary_eventIsDecaMoveSleeping_Parms), Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_SendDecaMoveHaptic_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_SendDecaMoveHaptic_Statics::Function_MetaDataParams[] = {
		{ "Category", "DecaMove" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_SendDecaMoveHaptic_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, nullptr, "SendDecaMoveHaptic", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_SendDecaMoveHaptic_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_SendDecaMoveHaptic_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_SendDecaMoveHaptic()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_SendDecaMoveHaptic_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_NoRegister()
	{
		return UDecaMoveBlueprintFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_DecaMoveSDK,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_CalibrateDecaMove, "CalibrateDecaMove" }, // 2951556947
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMovePostion, "GetDecaMovePostion" }, // 3669542272
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRawRotation, "GetDecaMoveRawRotation" }, // 2618315478
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveRotation, "GetDecaMoveRotation" }, // 2401235799
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveState, "GetDecaMoveState" }, // 3184112925
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetDecaMoveYawOffset, "GetDecaMoveYawOffset" }, // 2618450130
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveDoubleClicked, "GetIfDecaMoveDoubleClicked" }, // 225140744
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveSingleClicked, "GetIfDecaMoveSingleClicked" }, // 3061792636
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_GetIfDecaMoveTripleClicked, "GetIfDecaMoveTripleClicked" }, // 1079105435
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_IsDecaMoveSleeping, "IsDecaMoveSleeping" }, // 1965437424
		{ &Z_Construct_UFunction_UDecaMoveBlueprintFunctionLibrary_SendDecaMoveHaptic, "SendDecaMoveHaptic" }, // 1340357494
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "DecaMoveBlueprintFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/DecaMoveBlueprintFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDecaMoveBlueprintFunctionLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics::ClassParams = {
		&UDecaMoveBlueprintFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UDecaMoveBlueprintFunctionLibrary, 3093679962);
	template<> DECAMOVESDK_API UClass* StaticClass<UDecaMoveBlueprintFunctionLibrary>()
	{
		return UDecaMoveBlueprintFunctionLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UDecaMoveBlueprintFunctionLibrary(Z_Construct_UClass_UDecaMoveBlueprintFunctionLibrary, &UDecaMoveBlueprintFunctionLibrary::StaticClass, TEXT("/Script/DecaMoveSDK"), TEXT("UDecaMoveBlueprintFunctionLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDecaMoveBlueprintFunctionLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
