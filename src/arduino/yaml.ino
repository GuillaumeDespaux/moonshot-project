#define YAML_CONFIG_FILE "/config.yaml"

YAMLNode yamlnode = YAMLNode::loadStream( YAML_CONFIG_FILE );
const char* text = yamlnode.gettext( "Infrastructure" );

void print_YAML(void) {
    Serial.println(text);
}