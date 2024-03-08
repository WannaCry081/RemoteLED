from rest_framework import serializers
from api.models import Light


class LightSerializer(serializers.ModelSerializer):
    
    
    class Meta:
        
        model = Light
        fields = ["led"]