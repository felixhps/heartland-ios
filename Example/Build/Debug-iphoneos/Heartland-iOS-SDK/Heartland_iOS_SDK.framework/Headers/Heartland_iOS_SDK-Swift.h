// Generated by Apple Swift version 5.5 (swiftlang-1300.0.31.1 clang-1300.0.29.1)
#ifndef HEARTLAND_IOS_SDK_SWIFT_H
#define HEARTLAND_IOS_SDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import Foundation;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="Heartland_iOS_SDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

enum HpsTransactionType : NSUInteger;
@protocol GMSDeviceInterface;

SWIFT_CLASS("_TtC17Heartland_iOS_SDK14GMSBaseBuilder")
@interface GMSBaseBuilder : NSObject
@property (nonatomic, readonly) enum HpsTransactionType transactionType;
@property (nonatomic, readonly, unsafe_unretained) id <GMSDeviceInterface> _Nonnull device;
- (void)execute;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK20GMSBatchCloseBuilder_")
@protocol GMSBatchCloseBuilder
@end

enum HpsTransactionStatus : NSUInteger;
@class AID;
@class NSString;
@class HpsTerminalResponse;
@class NSError;

SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK20GMSClientAppDelegate_")
@protocol GMSClientAppDelegate
- (void)searchComplete;
- (void)deviceConnected;
- (void)deviceDisconnected;
- (void)deviceFound:(NSObject * _Nonnull)device;
- (void)onStatus:(enum HpsTransactionStatus)status;
- (void)requestAIDSelection:(NSArray<AID *> * _Nonnull)applications;
- (void)requestAmountConfirmation:(NSDecimal)amount;
- (void)requestPostalCode:(NSString * _Nonnull)maskedPan expiryDate:(NSString * _Nonnull)expiryDate cardholderName:(NSString * _Nonnull)cardholderName;
- (void)requestSaFApproval;
- (void)onTransactionComplete:(NSString * _Nonnull)result response:(HpsTerminalResponse * _Nonnull)response;
- (void)onTransactionCancelled;
- (void)onError:(NSError * _Nonnull)error;
@end

@class HpsConnectionConfig;

SWIFT_CLASS("_TtC17Heartland_iOS_SDK16GMSConfiguration")
@interface GMSConfiguration : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithConfig:(HpsConnectionConfig * _Nonnull)config OBJC_DESIGNATED_INITIALIZER;
+ (GMSConfiguration * _Nonnull)fromHpsConnectionConfig:(HpsConnectionConfig * _Nonnull)config SWIFT_WARN_UNUSED_RESULT;
@end

@class NSDecimalNumber;
@class HpsTransactionDetails;
@class HpsAddress;

SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK22GMSCreditAdjustBuilder_")
@protocol GMSCreditAdjustBuilder
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) HpsTransactionDetails * _Nullable details;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@property (nonatomic, copy) NSString * _Nullable cardHolderName;
@property (nonatomic, strong) HpsAddress * _Nullable address;
@end

@class HpsCreditCard;

SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK20GMSCreditAuthBuilder_")
@protocol GMSCreditAuthBuilder
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) HpsTransactionDetails * _Nullable details;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@property (nonatomic, copy) NSString * _Nullable cardHolderName;
@property (nonatomic, strong) HpsCreditCard * _Nullable creditCard;
@property (nonatomic, strong) HpsAddress * _Nullable address;
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK23GMSCreditCaptureBuilder_")
@protocol GMSCreditCaptureBuilder
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK22GMSCreditReturnBuilder_")
@protocol GMSCreditReturnBuilder
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@end

@class NSUUID;
enum ReversalReasonCode : NSInteger;

SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK24GMSCreditReversalBuilder_")
@protocol GMSCreditReversalBuilder
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSUUID * _Nullable clientTransactionId;
@property (nonatomic) enum ReversalReasonCode reason;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK20GMSCreditSaleBuilder_")
@protocol GMSCreditSaleBuilder
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) HpsTransactionDetails * _Nullable details;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@property (nonatomic, copy) NSString * _Nullable cardHolderName;
@property (nonatomic, strong) HpsCreditCard * _Nullable creditCard;
@property (nonatomic, strong) HpsAddress * _Nullable address;
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK20GMSCreditVoidBuilder_")
@protocol GMSCreditVoidBuilder
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK18GMSDeviceInterface_")
@protocol GMSDeviceInterface
- (void)processTransactionWithRequest:(GMSBaseBuilder * _Nonnull)request withTransactionType:(enum HpsTransactionType)transactionType;
@end

@class GMSWrapper;
@protocol GMSDeviceDelegate;
@protocol GMSTransactionDelegate;
@class NSMutableArray;
@class HpsTerminalInfo;

SWIFT_CLASS("_TtC17Heartland_iOS_SDK9GMSDevice")
@interface GMSDevice : NSObject <GMSClientAppDelegate, GMSDeviceInterface>
@property (nonatomic, strong) GMSWrapper * _Nullable gmsWrapper;
@property (nonatomic, strong) id <GMSDeviceDelegate> _Nullable deviceDelegate;
@property (nonatomic, strong) id <GMSTransactionDelegate> _Nullable transactionDelegate;
@property (nonatomic, strong) NSMutableArray * _Nonnull peripherals;
- (void)initialize;
- (void)scan;
- (void)stopScan;
- (void)getDeviceInfo;
- (void)connectDevice:(HpsTerminalInfo * _Nonnull)device;
- (void)processTransactionWithRequest:(GMSBaseBuilder * _Nonnull)builder withTransactionType:(enum HpsTransactionType)transactionType;
- (void)confirmAmount:(NSDecimal)amount;
- (void)confirmApplication:(AID * _Nonnull)application;
- (void)cancelTransaction;
- (void)deviceConnected;
- (void)deviceDisconnected;
- (void)searchComplete;
- (void)deviceFound:(NSObject * _Nonnull)device;
- (void)onStatus:(enum HpsTransactionStatus)status;
- (void)onTransactionCancelled;
- (void)onTransactionComplete:(NSString * _Nonnull)result response:(HpsTerminalResponse * _Nonnull)response;
- (void)requestAIDSelection:(NSArray<AID *> * _Nonnull)applications;
- (void)requestAmountConfirmation:(NSDecimal)amount;
- (void)requestPostalCode:(NSString * _Nonnull)maskedPan expiryDate:(NSString * _Nonnull)expiryDate cardholderName:(NSString * _Nonnull)cardholderName;
- (void)requestSaFApproval;
- (void)onError:(NSError * _Nonnull)error;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK17GMSDeviceDelegate_")
@protocol GMSDeviceDelegate
- (void)onConnected;
- (void)onDisconnected;
- (void)onError:(NSError * _Nonnull)deviceError;
- (void)onBluetoothDeviceList:(NSMutableArray * _Nonnull)peripherals;
@end


typedef SWIFT_ENUM(NSInteger, GMSErrorType, closed) {
  GMSErrorTypeConnectionError = 0,
  GMSErrorTypeSearchError = 1,
  GMSErrorTypeTransactionError = 2,
};


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK22GMSTransactionDelegate_")
@protocol GMSTransactionDelegate
- (void)onStatusUpdate:(enum HpsTransactionStatus)transactionStatus;
- (void)onConfirmAmount:(NSDecimal)amount;
- (void)onConfirmApplication:(NSArray<AID *> * _Nonnull)applications;
- (void)onTransactionComplete:(HpsTerminalResponse * _Nonnull)response;
- (void)onTransactionCancelled;
- (void)onError:(NSError * _Nonnull)error;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK22GMSTransactionResponse")
@interface GMSTransactionResponse : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK10GMSWrapper")
@interface GMSWrapper : NSObject
- (void)searchDevices;
- (void)cancelSearch;
- (void)cancelTransaction;
- (void)connectDevice:(HpsTerminalInfo * _Nonnull)device;
- (void)disconnect;
- (void)startTransaction:(GMSBaseBuilder * _Nonnull)builder withTransactionType:(enum HpsTransactionType)transactionType;
- (void)confirmAmountWithAmount:(NSDecimal)amount;
- (void)selectAIDWithAid:(AID * _Nonnull)aid;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface GMSWrapper (SWIFT_EXTENSION(Heartland_iOS_SDK))
- (void)onSearchComplete;
@end



@interface GMSWrapper (SWIFT_EXTENSION(Heartland_iOS_SDK))
- (void)requestAIDSelectionWithAids:(NSArray<AID *> * _Nonnull)aids;
- (void)requestPostalCodeWithMaskedPan:(NSString * _Nonnull)maskedPan expiryDate:(NSString * _Nonnull)expiryDate cardholderName:(NSString * _Nullable)cardholderName;
- (void)requestSaFApproval;
- (void)onTransactionCancelled;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK17HpsC2xBaseBuilder")
@interface HpsC2xBaseBuilder : GMSBaseBuilder
@end

@class HpsC2xDevice;

SWIFT_CLASS("_TtC17Heartland_iOS_SDK23HpsC2xBatchCloseBuilder")
@interface HpsC2xBatchCloseBuilder : HpsC2xBaseBuilder <GMSBatchCloseBuilder>
- (nonnull instancetype)initWithDevice:(HpsC2xDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK25HpsC2xCreditAdjustBuilder")
@interface HpsC2xCreditAdjustBuilder : HpsC2xBaseBuilder <GMSCreditAdjustBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) HpsTransactionDetails * _Nullable details;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@property (nonatomic, copy) NSString * _Nullable cardHolderName;
@property (nonatomic, strong) HpsAddress * _Nullable address;
- (nonnull instancetype)initWithDevice:(HpsC2xDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK23HpsC2xCreditAuthBuilder")
@interface HpsC2xCreditAuthBuilder : HpsC2xBaseBuilder <GMSCreditAuthBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) HpsTransactionDetails * _Nullable details;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@property (nonatomic, copy) NSString * _Nullable cardHolderName;
@property (nonatomic, strong) HpsCreditCard * _Nullable creditCard;
@property (nonatomic, strong) HpsAddress * _Nullable address;
- (nonnull instancetype)initWithDevice:(HpsC2xDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK26HpsC2xCreditCaptureBuilder")
@interface HpsC2xCreditCaptureBuilder : HpsC2xBaseBuilder <GMSCreditCaptureBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
- (nonnull instancetype)initWithDevice:(HpsC2xDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK25HpsC2xCreditReturnBuilder")
@interface HpsC2xCreditReturnBuilder : HpsC2xBaseBuilder <GMSCreditReturnBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, copy) NSString * _Nullable transactionId;
- (nonnull instancetype)initWithDevice:(HpsC2xDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK27HpsC2xCreditReversalBuilder")
@interface HpsC2xCreditReversalBuilder : HpsC2xBaseBuilder <GMSCreditReversalBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSUUID * _Nullable clientTransactionId;
@property (nonatomic) enum ReversalReasonCode reason;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, copy) NSString * _Nullable transactionId;
- (nonnull instancetype)initWithDevice:(HpsC2xDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK23HpsC2xCreditSaleBuilder")
@interface HpsC2xCreditSaleBuilder : HpsC2xBaseBuilder <GMSCreditSaleBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) HpsTransactionDetails * _Nullable details;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@property (nonatomic, copy) NSString * _Nullable cardHolderName;
@property (nonatomic, strong) HpsCreditCard * _Nullable creditCard;
@property (nonatomic, strong) HpsAddress * _Nullable address;
- (nonnull instancetype)initWithDevice:(HpsC2xDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK23HpsC2xCreditVoidBuilder")
@interface HpsC2xCreditVoidBuilder : HpsC2xBaseBuilder <GMSCreditVoidBuilder>
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, copy) NSString * _Nullable transactionId;
- (nonnull instancetype)initWithDevice:(HpsC2xDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK19IC2xDeviceInterface_")
@protocol IC2xDeviceInterface <GMSDeviceInterface>
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK12HpsC2xDevice")
@interface HpsC2xDevice : GMSDevice <IC2xDeviceInterface>
- (nonnull instancetype)initWithConfig:(HpsConnectionConfig * _Nonnull)config OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK20HpsC2xDeviceDelegate_")
@protocol HpsC2xDeviceDelegate <GMSDeviceDelegate>
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK11HpsC2xEnums")
@interface HpsC2xEnums : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK25HpsC2xTransactionDelegate_")
@protocol HpsC2xTransactionDelegate <GMSTransactionDelegate>
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK15HpsTerminalInfo")
@interface HpsTerminalInfo : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

typedef SWIFT_ENUM(NSUInteger, HpsTransactionStatus, closed) {
  HpsTransactionStatusWaitingForConfiguration = 0,
  HpsTransactionStatusConfiguringTerminal = 1,
  HpsTransactionStatusConfigurationFailedTryAgain = 2,
  HpsTransactionStatusReady = 3,
  HpsTransactionStatusStarted = 4,
  HpsTransactionStatusWaitingForCard = 5,
  HpsTransactionStatusInsertCard = 6,
  HpsTransactionStatusRemoveCard = 7,
  HpsTransactionStatusCardRemoved = 8,
  HpsTransactionStatusPleaseWait = 9,
  HpsTransactionStatusPleaseSeePhone = 10,
  HpsTransactionStatusUseMagstripe = 11,
  HpsTransactionStatusTryAgain = 12,
  HpsTransactionStatusSwipeErrorReSwipe = 13,
  HpsTransactionStatusNoEmvApps = 14,
  HpsTransactionStatusApplicationExpired = 15,
  HpsTransactionStatusCardReadError = 16,
  HpsTransactionStatusProcessing = 17,
  HpsTransactionStatusProcessingDoNotRemoveCard = 18,
  HpsTransactionStatusPresentCard = 19,
  HpsTransactionStatusPresentCardAgain = 20,
  HpsTransactionStatusInsertSwipeOrTryAnotherCard = 21,
  HpsTransactionStatusInsertOrSwipeCard = 22,
  HpsTransactionStatusMultipleCardDetected = 23,
  HpsTransactionStatusContactlessCardStillInField = 24,
  HpsTransactionStatusTransactionTerminated = 25,
  HpsTransactionStatusWaitingForTerminal = 26,
  HpsTransactionStatusCardDetected = 27,
  HpsTransactionStatusCardBlocked = 28,
  HpsTransactionStatusNotAuthorized = 29,
  HpsTransactionStatusNotAcceptedRemoveCard = 30,
  HpsTransactionStatusFallbackToMSR = 31,
  HpsTransactionStatusFallbackToChip = 32,
  HpsTransactionStatusWaitingForAmountConfirmation = 33,
  HpsTransactionStatusWaitingForAidSelection = 34,
  HpsTransactionStatusWaitingForPostalCode = 35,
  HpsTransactionStatusWaitingForSafApproval = 36,
  HpsTransactionStatusCardHolderBypassedPIN = 37,
  HpsTransactionStatusProcessingSaf = 38,
  HpsTransactionStatusRequestingOnlineProcessing = 39,
  HpsTransactionStatusReversal = 40,
  HpsTransactionStatusReversalInProgress = 41,
  HpsTransactionStatusComplete = 42,
  HpsTransactionStatusCancel = 43,
  HpsTransactionStatusCancelling = 44,
  HpsTransactionStatusCancelled = 45,
  HpsTransactionStatusError = 46,
  HpsTransactionStatusUnknown = 47,
  HpsTransactionStatusTerminalDeclined = 48,
};

typedef SWIFT_ENUM(NSUInteger, HpsTransactionType, closed) {
  HpsTransactionTypeBatchClose = 0,
  HpsTransactionTypeCreditAdjust = 1,
  HpsTransactionTypeCreditAuth = 2,
  HpsTransactionTypeCreditCapture = 3,
  HpsTransactionTypeCreditReturn = 4,
  HpsTransactionTypeCreditReversal = 5,
  HpsTransactionTypeCreditSale = 6,
  HpsTransactionTypeCreditVoid = 7,
  HpsTransactionTypeUnknown = 8,
};


SWIFT_CLASS("_TtC17Heartland_iOS_SDK22HpsWiseCubeBaseBuilder")
@interface HpsWiseCubeBaseBuilder : GMSBaseBuilder
@end

@class HpsWiseCubeDevice;

SWIFT_CLASS("_TtC17Heartland_iOS_SDK28HpsWiseCubeBatchCloseBuilder")
@interface HpsWiseCubeBatchCloseBuilder : HpsWiseCubeBaseBuilder <GMSBatchCloseBuilder>
- (nonnull instancetype)initWithDevice:(HpsWiseCubeDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK30HpsWiseCubeCreditAdjustBuilder")
@interface HpsWiseCubeCreditAdjustBuilder : HpsWiseCubeBaseBuilder <GMSCreditAdjustBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) HpsTransactionDetails * _Nullable details;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@property (nonatomic, copy) NSString * _Nullable cardHolderName;
@property (nonatomic, strong) HpsAddress * _Nullable address;
- (nonnull instancetype)initWithDevice:(HpsWiseCubeDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK28HpsWiseCubeCreditAuthBuilder")
@interface HpsWiseCubeCreditAuthBuilder : HpsWiseCubeBaseBuilder <GMSCreditAuthBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) HpsTransactionDetails * _Nullable details;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@property (nonatomic, copy) NSString * _Nullable cardHolderName;
@property (nonatomic, strong) HpsCreditCard * _Nullable creditCard;
@property (nonatomic, strong) HpsAddress * _Nullable address;
- (nonnull instancetype)initWithDevice:(HpsWiseCubeDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK31HpsWiseCubeCreditCaptureBuilder")
@interface HpsWiseCubeCreditCaptureBuilder : HpsWiseCubeBaseBuilder <GMSCreditCaptureBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
- (nonnull instancetype)initWithDevice:(HpsWiseCubeDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK30HpsWiseCubeCreditReturnBuilder")
@interface HpsWiseCubeCreditReturnBuilder : HpsWiseCubeBaseBuilder <GMSCreditReturnBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, copy) NSString * _Nullable transactionId;
- (nonnull instancetype)initWithDevice:(HpsWiseCubeDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK32HpsWiseCubeCreditReversalBuilder")
@interface HpsWiseCubeCreditReversalBuilder : HpsWiseCubeBaseBuilder <GMSCreditReversalBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSUUID * _Nullable clientTransactionId;
@property (nonatomic) enum ReversalReasonCode reason;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, copy) NSString * _Nullable transactionId;
- (nonnull instancetype)initWithDevice:(HpsWiseCubeDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK28HpsWiseCubeCreditSaleBuilder")
@interface HpsWiseCubeCreditSaleBuilder : HpsWiseCubeBaseBuilder <GMSCreditSaleBuilder>
@property (nonatomic, strong) NSDecimalNumber * _Nullable amount;
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, strong) HpsTransactionDetails * _Nullable details;
@property (nonatomic, strong) NSDecimalNumber * _Nullable gratuity;
@property (nonatomic, copy) NSString * _Nullable transactionId;
@property (nonatomic, copy) NSString * _Nullable cardHolderName;
@property (nonatomic, strong) HpsCreditCard * _Nullable creditCard;
@property (nonatomic, strong) HpsAddress * _Nullable address;
- (nonnull instancetype)initWithDevice:(HpsWiseCubeDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK28HpsWiseCubeCreditVoidBuilder")
@interface HpsWiseCubeCreditVoidBuilder : HpsWiseCubeBaseBuilder <GMSCreditVoidBuilder>
@property (nonatomic, copy) NSString * _Nullable referenceNumber;
@property (nonatomic, copy) NSString * _Nullable transactionId;
- (nonnull instancetype)initWithDevice:(HpsWiseCubeDevice * _Nonnull)device OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_PROTOCOL("_TtP17Heartland_iOS_SDK24IWiseCubeDeviceInterface_")
@protocol IWiseCubeDeviceInterface <GMSDeviceInterface>
@end


SWIFT_CLASS("_TtC17Heartland_iOS_SDK17HpsWiseCubeDevice")
@interface HpsWiseCubeDevice : GMSDevice <IWiseCubeDeviceInterface>
- (nonnull instancetype)initWithConfig:(HpsConnectionConfig * _Nonnull)config OBJC_DESIGNATED_INITIALIZER;
@end




typedef SWIFT_ENUM(NSInteger, ReversalReasonCode, closed) {
  ReversalReasonCodeCUSTOMERCANCELLATION = 0,
  ReversalReasonCodeTERMINALERROR = 1,
  ReversalReasonCodeTIMEOUT = 2,
  ReversalReasonCodePARTIALREVERSAL = 3,
  ReversalReasonCodeNOREASON = 4,
};

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif