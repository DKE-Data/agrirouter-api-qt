################################################################################
# Agrirouter lib files
################################################################################
set(LIB_NAME CCIAgrirouter)
set(LIB_VERSION_MAJOR 1)
set(LIB_VERSION_MINOR 0)
set(LIB_VERSION_PATCH 0)
set(LIB_VERSION_STRING ${LIB_VERSION_MAJOR}.${LIB_VERSION_MINOR}.${LIB_VERSION_PATCH})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc
                    ${CMAKE_CURRENT_SOURCE_DIR}/inc/Protobuf
                    ${CMAKE_CURRENT_SOURCE_DIR}/src
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPRequest
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPRequest/Get
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/HTTPRequest/Post
)

include_directories(SYSTEM
    ${PROTOBUF_INCLUDE_DIR}
)

set(CCIAgrirouter_PROTOBUF_HDRS
    inc/Protobuf/cloud-provider-integration/cloud-virtualized-app-registration.pb.h
    inc/Protobuf/commons/chunk.pb.h
    inc/Protobuf/commons/message.pb.h
    inc/Protobuf/messaging/request/request.pb.h
    inc/Protobuf/messaging/request/payload/account/endpoints.pb.h
    inc/Protobuf/messaging/request/payload/efdi/grpc-efdi.pb.h
    inc/Protobuf/messaging/request/payload/endpoint/capabilities.pb.h
    inc/Protobuf/messaging/request/payload/endpoint/subscription.pb.h
    inc/Protobuf/messaging/request/payload/feed/feed-requests.pb.h
    inc/Protobuf/messaging/response/response.pb.h
    inc/Protobuf/messaging/response/payload/account/endpoints.pb.h
    inc/Protobuf/messaging/response/payload/endpoint/capability.pb.h
    inc/Protobuf/messaging/response/payload/feed/feed-response.pb.h
)

set(CCIAgrirouter_PROTOBUF_SRCS
    src/Protobuf/cloud-provider-integration/cloud-virtualized-app-registration.pb.cc
    src/Protobuf/commons/chunk.pb.cc
    src/Protobuf/commons/message.pb.cc
    src/Protobuf/messaging/request/request.pb.cc
    src/Protobuf/messaging/request/payload/account/endpoints.pb.cc
    src/Protobuf/messaging/request/payload/efdi/grpc-efdi.pb.cc
    src/Protobuf/messaging/request/payload/endpoint/capabilities.pb.cc
    src/Protobuf/messaging/request/payload/endpoint/subscription.pb.cc
    src/Protobuf/messaging/request/payload/feed/feed-requests.pb.cc
    src/Protobuf/messaging/response/response.pb.cc
    src/Protobuf/messaging/response/payload/account/endpoints.pb.cc
    src/Protobuf/messaging/response/payload/endpoint/capability.pb.cc
    src/Protobuf/messaging/response/payload/feed/feed-response.pb.cc
)

set(CCIAgrirouter_PUBLIC_HDRS
    inc/CCIAgrirouter/AgrirouterClient.h
    inc/CCIAgrirouter/ICommunicationInterface.h
    inc/CCIAgrirouter/CCIAgrirouter_export.h
    inc/CCIAgrirouter/Globals.h
)

set(CCIAgrirouter_HDRS
    src/AgrirouterClientPrivate.h
    src/AgrirouterMessage.h
    src/AgrirouterMessageUtils.h
    src/MessageConverter.h
    src/MessageQueue.h
    src/Settings.h
    src/Utils.h
    src/HTTPRequest/MessagingService.h
    src/HTTPRequest/Registration.h
    src/HTTPRequest/Post/MessageSender.h
    src/HTTPRequest/Get/ResponsePoll.h
    src/HTTPRequest/Get/ResponsePollLoop.h
)

set(CCIAgrirouter_SRCS
    src/AgrirouterClient.cpp
    src/AgrirouterClientPrivate.cpp
    src/AgrirouterMessage.cpp
    src/MessageConverter.cpp
    src/MessageQueue.cpp
    src/Settings.cpp
    src/HTTPRequest/MessagingService.cpp
    src/HTTPRequest/Registration.cpp
    src/HTTPRequest/Post/MessageSender.cpp
    src/HTTPRequest/Get/ResponsePoll.cpp
    src/HTTPRequest/Get/ResponsePollLoop.cpp
    ${CCIAgrirouter_PROTOBUF_SRCS}
)

################################################################################
# Build lib
################################################################################
#only needed for shared lib
#add_definitions("-DBUILDING_CCIAGRIROUTER")

add_library(${LIB_NAME} STATIC
    ${CCIAgrirouter_SRCS}
    ${CCIAgrirouter_HDRS}
    ${CCIAgrirouter_PUBLIC_HDRS}
    ${CCIAgrirouter_PROTOBUF_HDRS}
)

target_link_libraries(${LIB_NAME}
    Qt5::Core
    Qt5::Network
    ${PROTOBUF_LIBRARIES}
)

set_target_properties(${LIB_NAME}
    PROPERTIES
    VERSION ${LIB_VERSION_STRING}
    SOVERSION ${LIB_VERSION_MAJOR}
)

################################################################################
# install shared lib
################################################################################
#install(TARGETS ${LIB_NAME} DESTINATION lib)
#install(FILES ${CCIAgrirouter_PUBLIC_HDRS} DESTINATION include/${LIB_NAME}/)
