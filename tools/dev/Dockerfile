# MetaCall Depends image
FROM metacall/core:deps AS dev

# [Labels remain unchanged]

# Arguments
ARG METACALL_PATH

# Echo METACALL_PATH for debugging
RUN echo "METACALL_PATH is set to: $METACALL_PATH"

# Environment variables
ENV LOADER_LIBRARY_PATH=$METACALL_PATH/build \
    LOADER_SCRIPT_PATH=$METACALL_PATH/build/scripts \
    CONFIGURATION_PATH=$METACALL_PATH/build/configurations/global.json \
    SERIAL_LIBRARY_PATH=$METACALL_PATH/build \
    DETOUR_LIBRARY_PATH=$METACALL_PATH/build \
    PORT_LIBRARY_PATH=$METACALL_PATH/build \
    DEBIAN_FRONTEND=noninteractive \
    NODE_PATH=/usr/lib/node_modules \
    DOTNET_CLI_TELEMETRY_OPTOUT=true

# Define working directory
WORKDIR $METACALL_PATH

# Copy MetaCall dependencies
COPY tools $METACALL_PATH/tools
COPY . $METACALL_PATH

# List contents of tools directory
RUN ls -la $METACALL_PATH/tools

# Configure MetaCall build tool script
RUN chmod 500 $METACALL_PATH/tools/metacall-configure.sh \
    && chmod 500 $METACALL_PATH/tools/metacall-build.sh \
    && mkdir -p $METACALL_PATH/build \
    && ls -la $METACALL_PATH/tools

# Configure MetaCall libraries and build runtimes if needed
ARG METACALL_BUILD_TYPE
ARG METACALL_BUILD_OPTIONS

# Echo build arguments for verification
RUN echo "Build Type: $METACALL_BUILD_TYPE" \
    && echo "Build Options: $METACALL_BUILD_OPTIONS"

RUN cd $METACALL_PATH/build \
    && $METACALL_PATH/tools/metacall-configure.sh ${METACALL_BUILD_TYPE} ${METACALL_BUILD_OPTIONS}

# Build test and install MetaCall libraries
RUN cd $METACALL_PATH/build \
    && $METACALL_PATH/tools/metacall-build.sh ${METACALL_BUILD_TYPE} ${METACALL_BUILD_OPTIONS}
