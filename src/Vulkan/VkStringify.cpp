// Copyright 2019 The SwiftShader Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "VkStringify.hpp"
#include "VkDebug.hpp"
#include "vulkan/vk_ext_provoking_vertex.h"

#include <iostream>
#include <map>
#include <string>

namespace vk {

std::string Stringify(VkStructureType value)
{
#ifndef NDEBUG
	// Since C++ hasn't given us introspection on enums, we can't just "get" an
	// enum name from an enum value (at least not without some crazy header
	// file hacks). So I copied the entire list of VK_STRUCTURE_TYPE defined in
	// vulkan/vulkan_core.h.
	//
	// If vulkan_core.h is updated to include new structure types, and this list
	// becomes out of date, then this function will throw a warning if someone
	// tries to stringify that enum value.
	static const std::map<VkStructureType, const char *> strings = {
#	define INSERT_ELEMENT(p) std::make_pair(p, #    p)
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_APPLICATION_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SUBMIT_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_SPARSE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_FENCE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EVENT_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_BARRIER),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PRESENT_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_OBJECT_TABLE_CREATE_INFO_NVX),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NVX),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_CMD_PROCESS_COMMANDS_INFO_NVX),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_CMD_RESERVE_SPACE_FOR_COMMANDS_INFO_NVX),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_LIMITS_NVX),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GENERATED_COMMANDS_FEATURES_NVX),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_HDR_METADATA_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SUBPASS_END_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_GEOMETRY_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES2_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT_KHR),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_BEGIN_RANGE),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_END_RANGE),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_RANGE_SIZE),
		INSERT_ELEMENT(VK_STRUCTURE_TYPE_MAX_ENUM)
#	undef INSERT_ELEMENT
	};
	auto it = strings.find(value);
	if(it != strings.end())
	{
		return std::string(it->second);
	}
	else
	{
		WARN("Stringify(VkStructureType v) is out of date. Please update it to match vulkan/vulkan_core.h");
		return std::to_string(value);
	}
#else  // if not debug:
	return std::to_string(value);
#endif
}

}  // namespace vk
