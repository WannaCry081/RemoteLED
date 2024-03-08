from rest_framework import viewsets, mixins
from api.core.v1.serializers import LightSerializer
from api.models import Light


class LightViewSet(viewsets.GenericViewSet,
                   mixins.CreateModelMixin,
                   mixins.RetrieveModelMixin,
                   mixins.UpdateModelMixin): 
    
    queryset = Light.objects.all()
    serializer_class = LightSerializer